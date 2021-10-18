#include "MainWindow.h"
#include "CodeEditor.h"
#include "GLSLCompleter.h"
#include "SyntaxStyle.h"
#include "GLSLHighlighter.h"
#include "Openglwidget.h"

#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QSpinBox>
#include <QGroupBox>
#include <QLabel>
#include <QMenuBar>
#include <QDockWidget>
#include <QToolBar>
#include <QComboBox>
#include <QListWidget>
#include <QTextStream>
#include <QGuiApplication>
#include <QSaveFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QStatusBar>

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	m_setupLayout(nullptr),
	m_codeEditor(nullptr),
	m_renderArea(nullptr),
	m_completers(),
	m_highlighters(),
	m_styles()
{
	initData();
	initMenuBar();
	initToolBar();
	createWidgets();
	createDockWidgets();
	setupWidgets();
	performConnections();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initData()
{
	m_codeSamples = {
		{"sample 1", loadCode(":/code_samples/shader_00.glsl")},
		{"sample 2", loadCode(":/code_samples/shader_01.glsl")},
		{"sample 3", loadCode(":/code_samples/shader_02.glsl")},
		{"sample 4", loadCode(":/code_samples/shader_03.glsl")},
		{"sample 5", loadCode(":/code_samples/shader_04.glsl")}
	};

	m_completers = {
		{"GLSL", new GLSLCompleter(this)},
	};

	m_highlighters = {
		{"GLSL", new GLSLHighlighter},
	};

	m_styles = {
		{"Default", SyntaxStyle::defaultStyle()}
	};
}

void MainWindow::initMenuBar()
{
	fileMenu = menuBar()->addMenu("File");

	newAct = new QAction(QIcon(QPixmap(":/icons/new.png")), tr("&New"), this);
	newAct->setShortcuts(QKeySequence::New);
	newAct->setStatusTip(tr("Create a new file"));
	fileMenu->addAction(newAct);

	openAct = new QAction(QIcon(QPixmap(":/icons/open.png")), tr("&Open..."), this);
	openAct->setShortcuts(QKeySequence::Open);
	openAct->setStatusTip(tr("Open an existing file"));
	fileMenu->addAction(openAct);

	saveAct = new QAction(QIcon(QPixmap(":/icons/save.png")), tr("&Save"), this);
	saveAct->setShortcuts(QKeySequence::Save);
	saveAct->setStatusTip(tr("Save the document to disk"));
	fileMenu->addAction(saveAct);

	fileMenu->addSeparator();

	exitaction = new QAction(QIcon(QPixmap(":/icons/exit.png")), tr("&Exit"), this);
	exitaction->setShortcut(tr("Ctrl+Q"));
	exitaction->setStatusTip(tr("exit from program"));
	connect(exitaction, &QAction::triggered, this, &QWidget::close);
	fileMenu->addAction(exitaction);

	helpMenu = menuBar()->addMenu("Help");
	aboutAct = new QAction(QIcon(":/icons/about.png"), tr("About"), this);
	helpMenu->addAction(aboutAct);
}

void MainWindow::initToolBar()
{
	toolbar = new QToolBar();
	toolbar->setMovable(false);
	toolbar->addAction(newAct);
	toolbar->addAction(openAct);
	toolbar->addAction(saveAct);

	toolbar->addSeparator();

	toolbar->addWidget(new QLabel("   Examples  "));

	m_examplesList = new QComboBox();
	m_examplesList->setMinimumWidth(150);

	for(auto el : m_codeSamples)
		m_examplesList->addItem(el.first);

	toolbar->addWidget(m_examplesList);
	addToolBar(toolbar);
}

void MainWindow::init_statusBar()
{
	statusBar()->addPermanentWidget(new QLabel(""));
}

QString MainWindow::loadCode(QString path)
{
	QFile fl(path);

	if (!fl.open(QIODevice::ReadOnly))
	{
		return QString();
	}

	return fl.readAll();
}

void MainWindow::loadStyle(QString path)
{
	QFile fl(path);

	if (!fl.open(QIODevice::ReadOnly))
	{
		return;
	}

	auto style = new SyntaxStyle(this);

	if (!style->load(fl.readAll()))
	{
		delete style;
		return;
	}

	m_styles.append({ style->name(), style });
}

void MainWindow::createWidgets()
{
	// Layout
	auto container = new QWidget(this);
	setCentralWidget(container);

	auto hBox = new QHBoxLayout(container);

	// CodeEditor
	m_codeEditor = new CodeEditor(this);
	hBox->addWidget(m_codeEditor);

	// window maxmize by defautlt
	setWindowState(Qt::WindowMaximized);
}

void MainWindow::createDockWidgets()
{
	// render window
	m_dockedRenderWindow = new QDockWidget("Render",this);
	m_dockedRenderWindow->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
	m_renderArea = new Openglwidget(m_dockedRenderWindow);
	m_dockedRenderWindow->setWidget(m_renderArea);
	addDockWidget(Qt::RightDockWidgetArea, m_dockedRenderWindow);

	// error window
	m_dockedErrorWindow = new QDockWidget("Errors", this);
	m_dockedErrorWindow->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
	m_errorsList = new QListWidget();
	m_dockedErrorWindow->setWidget(m_errorsList);
	addDockWidget(Qt::RightDockWidgetArea, m_dockedErrorWindow);
}

void MainWindow::setupWidgets()
{
	setWindowIcon(QIcon(":/icons/icon.png"));

	// CodeEditor
	m_codeEditor->setPlainText(m_codeSamples[0].second);
	m_codeEditor->setSyntaxStyle(m_styles[0].second);
	m_codeEditor->setCompleter(m_completers[0].second);
	m_codeEditor->setHighlighter(m_highlighters[0].second);

	setCurrentFile(QString());
}

void MainWindow::textchanged()
{
	// mark code as modified
	setWindowModified(m_codeEditor->document()->isModified());

	// compile new code edited
	auto code = m_codeEditor->toPlainText().toStdString();
	m_renderArea->ps_shader = code.c_str();
	auto result = m_renderArea->compile_shader();

	if (result.size() > 0)
	{
		m_errorsList->clear();
		for (auto error : result)
			m_errorsList->addItem(error);
	}
	else m_errorsList->clear();
}

void MainWindow::render_window_floating(bool topLevel)
{
	textchanged();
	update();
}

void MainWindow::selected_example_changed(int index)
{
	m_codeEditor->setPlainText(m_codeSamples[index].second);
	textchanged();
	update();
}

void MainWindow::performConnections()
{
	// menu actions
	connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
	connect(saveAct, &QAction::triggered, this, &MainWindow::saveFile);
	connect(openAct, &QAction::triggered, this, &MainWindow::openFile);

	// code editor
	connect(m_codeEditor, &CodeEditor::textChanged, this, &MainWindow::textchanged);
	connect(m_dockedRenderWindow, &QDockWidget::topLevelChanged, this, &MainWindow::render_window_floating);
	connect(m_examplesList, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::selected_example_changed);
}

void MainWindow::setCurrentFile(QString filename)
{
	m_filename = filename;
	m_codeEditor->document()->setModified(false);

	setWindowModified(false);

	QString showname = m_filename + " - Shader++";

	if (m_filename.isEmpty())
		showname = "untitled.glsl - Shader++";

	setWindowFilePath(showname);
}

bool MainWindow::maybesave()
{
	if (!m_codeEditor->document()->isModified())
		return true;

	auto ret = QMessageBox::warning(this, "Warning", "the document is modified \n do you want to save ? ",
		QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

	switch (ret)
	{
	case QMessageBox::Save:
		saveFile();
		break;
	case QMessageBox::Cancel:
		return false;
		break;
	case QMessageBox::Discard:
		break;
	default:
		break;
	}

	return true;
}

void MainWindow::saveFile()
{
	if (m_filename.isEmpty())
	{
		saveAsFile();
	}
	else
	{
		QGuiApplication::setOverrideCursor(Qt::WaitCursor);

		QSaveFile file(m_filename);

		if (file.open(QFile::WriteOnly | QFile::Text))
		{
			QTextStream out(&file);
			out << m_codeEditor->document()->toPlainText();

			if (!file.commit())
			{
				QMessageBox::warning(this, "warning", "error in saving file");
			}

		}
		else
		{
			QMessageBox::warning(this, "warning", "error in open file");
		}

		QGuiApplication::restoreOverrideCursor();
		setCurrentFile(m_filename);
		statusBar()->showMessage("file saved", 2000);
	}
}

void MainWindow::saveAsFile()
{
	QFileDialog dialog(this);

	dialog.setWindowModality(Qt::WindowModal);
	dialog.setAcceptMode(QFileDialog::AcceptSave);

	if (dialog.exec() != QDialog::Accepted)
	{
		// erorr
	}
	else
	{
		m_filename = dialog.selectedFiles().first();
		setCurrentFile(m_filename);
		saveFile();
	}
}

void MainWindow::newFile()
{
	if (maybesave())
	{
		m_codeEditor->clear();
		setCurrentFile(QString());
	}
}

void MainWindow::openFile()
{
	if (maybesave())
	{
		m_filename = QFileDialog::getOpenFileName(this);

		if (!m_filename.isEmpty())
		{
			QFile file(m_filename);

			if (!file.open(QFile::ReadOnly | QFile::Text))
			{
				QMessageBox::warning(this, "Warning", "erorr loading file");
			}

			QTextStream in(&file);

			QGuiApplication::setOverrideCursor(Qt::WaitCursor);
			m_codeEditor->document()->setPlainText(in.readAll());
			QGuiApplication::restoreOverrideCursor();

			setCurrentFile(m_filename);
		}
	}
}