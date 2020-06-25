#include "Openglwidget.h"

Openglwidget::Openglwidget(QWidget * parent)
	: QOpenGLWidget(parent)
{
	setMinimumSize(800, 600);
}

Openglwidget::~Openglwidget()
{
}

void Openglwidget::initializeGL()
{
	
}

void Openglwidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 0, 0, 1);
}

void Openglwidget::resizeGL(int width, int height)
{
}

void Openglwidget::mousePressEvent(QMouseEvent * event)
{
}

void Openglwidget::mouseReleaseEvent(QMouseEvent * event)
{
}

void Openglwidget::mouseMoveEvent(QMouseEvent * event)
{
}

void Openglwidget::wheelEvent(QWheelEvent * event)
{
}

void Openglwidget::keyPressEvent(QKeyEvent * event)
{
}

void Openglwidget::keyReleaseEvent(QKeyEvent * event)
{
}
