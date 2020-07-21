#include "FindWidget.h"

#include <QtWidgets>

FindWidget::FindWidget(QWidget  *parent) : QDialog(parent)
{
	setGeometry(200,200,0,0);

	label = new QLabel(tr("Find &what:"));
	lineEdit = new QLineEdit;
	label->setBuddy(lineEdit);


	findButton = new QPushButton(tr("&Find"));
	findButton->setDefault(true);

	buttonBox = new QDialogButtonBox(Qt::Vertical);
	buttonBox->addButton(findButton, QDialogButtonBox::ActionRole);

	QHBoxLayout *topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout *leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout);

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->setSizeConstraint(QLayout::SetFixedSize);
	mainLayout->addLayout(leftLayout, 0, 0);
	mainLayout->addWidget(buttonBox, 0, 1);

	setLayout(mainLayout);

	setWindowTitle(tr("Find"));
}

FindWidget::~FindWidget()
{

}
