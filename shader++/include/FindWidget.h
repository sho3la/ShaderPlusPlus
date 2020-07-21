#pragma once
#include <QDialog>

class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class CodeEditor;

class FindWidget : public QDialog
{
	Q_OBJECT

public:
	FindWidget(QWidget * parent = nullptr);

	~FindWidget();

	QString getKeyWord();
	void setKeyWord(QString word);
	void setCodeEditor(CodeEditor* ptr);

public Q_SLOTS:
	void find();

private:

	void performConnections();

	QLabel *label;
	QLineEdit *lineEdit;
	QDialogButtonBox *buttonBox;
	QPushButton *findButton;
	CodeEditor* codeeditor;
};