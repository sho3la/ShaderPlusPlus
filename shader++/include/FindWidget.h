#pragma once
#include <QDialog>

class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindWidget : public QDialog
{
	Q_OBJECT

public:
	FindWidget(QWidget * parent = nullptr);

	~FindWidget();

private:
	QLabel *label;
	QLineEdit *lineEdit;
	QCheckBox *caseCheckBox;
	QCheckBox *fromStartCheckBox;
	QCheckBox *wholeWordsCheckBox;
	QCheckBox *searchSelectionCheckBox;
	QCheckBox *backwardCheckBox;
	QDialogButtonBox *buttonBox;
	QPushButton *findButton;
	QPushButton *moreButton;
	QWidget *extension;
};