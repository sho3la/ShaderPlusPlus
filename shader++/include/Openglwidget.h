#pragma once
#include <glew.h>
#include <QOpenGLWidget>

class Openglwidget : public QOpenGLWidget
{
public:
	Openglwidget(QWidget *parent = nullptr);

	~Openglwidget();

	void compile_shader();
	const char* ps_shader;

protected:
	void initializeGL() override;
	void paintGL() override;
	void resizeGL(int width, int height) override;

	//mouse events
	void mousePressEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void wheelEvent(QWheelEvent *event);

	//keyboard events
	void keyPressEvent(QKeyEvent *event) override;
	void keyReleaseEvent(QKeyEvent *event) override;

private:
	const char* vs_shader;
	int shaderProgram;
	unsigned int VBO, VAO, EBO;
};