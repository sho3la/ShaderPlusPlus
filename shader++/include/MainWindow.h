#pragma once
#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QPair>

class QVBoxLayout;
class QComboBox;
class QCheckBox;
class QSpinBox;
class QCompleter;
class QDockWidget;

class SyntaxStyle;
class StyleSyntaxHighlighter;
class CodeEditor;
class Openglwidget;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);

	~MainWindow();

private:

	void loadStyle(QString path);

	QString loadCode(QString path);

	void initData();

	void initMenuBar();

	void initToolBar();

	void createWidgets();

	void createDockWidgets();

	void setupWidgets();

	void textchanged();

	void render_window_floating(bool topLevel);

	void selected_example_changed(int index);

	void performConnections();

	QVBoxLayout* m_setupLayout;

	QDockWidget *m_dockedWindow;

	CodeEditor* m_codeEditor;
	Openglwidget* m_renderArea;


	QVector<QPair<QString, QString>> m_codeSamples;
	QVector<QPair<QString, QCompleter*>> m_completers;
	QVector<QPair<QString, StyleSyntaxHighlighter*>> m_highlighters;
	QVector<QPair<QString, SyntaxStyle*>> m_styles;

	QMenu* fileMenu;
	QMenu* helpMenu;

	QAction* newAct;
	QAction* openAct;
	QAction* saveAct;
	QAction* saveasAct;
	QAction* exitaction;
	QAction* aboutAct;

	QToolBar* toolbar;
	QComboBox* m_examplesList;
};