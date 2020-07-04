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

	void createWidgets();

	void createDockWidgets();

	void setupWidgets();

	void textchanged();

	void render_window_floating(bool topLevel);

	void performConnections();

	QVBoxLayout* m_setupLayout;

	QDockWidget *dock;

	CodeEditor* m_codeEditor;
	Openglwidget* m_renderArea;


	QVector<QPair<QString, QString>> m_codeSamples;
	QVector<QPair<QString, QCompleter*>> m_completers;
	QVector<QPair<QString, StyleSyntaxHighlighter*>> m_highlighters;
	QVector<QPair<QString, SyntaxStyle*>> m_styles;
};