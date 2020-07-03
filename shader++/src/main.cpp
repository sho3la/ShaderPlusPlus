#include <QApplication>

#include <MainWindow.h>

int main(int argc, char** argv)
{
	// Creating application
	QApplication a(argc, argv);

	// Creating main window
	MainWindow w;
	w.show();

	return QApplication::exec();
}