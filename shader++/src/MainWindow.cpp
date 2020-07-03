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
	createWidgets();
	setupWidgets();
	performConnections();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initData()
{
	m_codeSamples = {
		{"GLSL", loadCode(":/code_samples/shader.glsl")},
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
	auto fileMenu = menuBar()->addMenu("File");

	auto newAct = new QAction(QIcon(QPixmap(":/icons/new.png")), tr("&New"), this);
	newAct->setShortcuts(QKeySequence::New);
	newAct->setStatusTip(tr("Create a new file"));
	fileMenu->addAction(newAct);

	auto openAct = new QAction(QIcon(QPixmap(":/icons/open.png")), tr("&Open..."), this);
	openAct->setShortcuts(QKeySequence::Open);
	openAct->setStatusTip(tr("Open an existing file"));
	fileMenu->addAction(openAct);

	auto saveAct = new QAction(QIcon(QPixmap(":/icons/save.png")), tr("&Save"), this);
	saveAct->setShortcuts(QKeySequence::Save);
	saveAct->setStatusTip(tr("Save the document to disk"));
	fileMenu->addAction(saveAct);

	auto saveasAct = new QAction(QIcon(QPixmap(":/icons/save_as.png")), tr("&SaveAs"), this);
	saveasAct->setShortcut(tr("Ctrl+Shift+S"));
	saveasAct->setStatusTip(tr("Save the document to disk"));
	fileMenu->addAction(saveasAct);

	fileMenu->addSeparator();

	auto exitaction = new QAction(QIcon(QPixmap(":/icons/exit.png")), tr("&Exit"), this);
	exitaction->setShortcut(tr("Ctrl+Q"));
	exitaction->setStatusTip(tr("exit from program"));
	connect(exitaction, &QAction::triggered, this, &QWidget::close);
	fileMenu->addAction(exitaction);

	auto helpMenu = menuBar()->addMenu("Help");
	auto aboutAct = new QAction(QIcon(":/icons/about.png"), tr("About"), this);
	helpMenu->addAction(aboutAct);
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


	m_renderArea = new Openglwidget(container);
	hBox->addWidget(m_renderArea);
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

void MainWindow::performConnections()
{
	connect(m_codeEditor, &CodeEditor::textChanged, this, &MainWindow::textchanged);
}
