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
		{"sample 2", loadCode(":/code_samples/shader_01.glsl")}
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

	saveasAct = new QAction(QIcon(QPixmap(":/icons/save_as.png")), tr("&SaveAs"), this);
	saveasAct->setShortcut(tr("Ctrl+Shift+S"));
	saveasAct->setStatusTip(tr("Save the document to disk"));
	fileMenu->addAction(saveasAct);

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
	toolbar->addAction(newAct);
	toolbar->addAction(openAct);
	toolbar->addAction(saveAct);
	toolbar->addAction(saveasAct);

	toolbar->addSeparator();

	toolbar->addWidget(new QLabel("   Examples  "));

	m_examplesList = new QComboBox();
	m_examplesList->setMinimumWidth(150);

	for(auto el : m_codeSamples)
		m_examplesList->addItem(el.first);

	toolbar->addWidget(m_examplesList);
	addToolBar(toolbar);
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
	m_dockedWindow = new QDockWidget("Render",this);
	m_dockedWindow->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);

	m_renderArea = new Openglwidget(m_dockedWindow);

	m_dockedWindow->setWidget(m_renderArea);
	addDockWidget(Qt::RightDockWidgetArea, m_dockedWindow);
}

void MainWindow::setupWidgets()
{
	setWindowTitle("Shader++");
	setWindowIcon(QIcon(":/icons/icon.png"));

	// CodeEditor
	m_codeEditor->setPlainText(m_codeSamples[0].second);
	m_codeEditor->setSyntaxStyle(m_styles[0].second);
	m_codeEditor->setCompleter(m_completers[0].second);
	m_codeEditor->setHighlighter(m_highlighters[0].second);
}

void MainWindow::textchanged()
{
	auto nn = m_codeEditor->toPlainText().toStdString();
	m_renderArea->ps_shader = nn.c_str();
	m_renderArea->compile_shader();
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
	connect(m_codeEditor, &CodeEditor::textChanged, this, &MainWindow::textchanged);
	connect(m_dockedWindow, &QDockWidget::topLevelChanged, this, &MainWindow::render_window_floating);
	connect(m_examplesList, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::selected_example_changed);
}
