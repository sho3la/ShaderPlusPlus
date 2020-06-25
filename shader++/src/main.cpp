#include <QApplication>

#include <Openglwidget.h>

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Openglwidget* w = new Openglwidget();
	w->show();

	return app.exec();
}