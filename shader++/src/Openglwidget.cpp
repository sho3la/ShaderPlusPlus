#include "Openglwidget.h"
#include <QMessageBox>

Openglwidget::Openglwidget(QWidget * parent)
	: QOpenGLWidget(parent)
{
	setMinimumSize(800, 300);
}

Openglwidget::~Openglwidget()
{
}

void Openglwidget::initializeGL()
{

	if (glewInit())
	{
		QMessageBox::warning(this, "Error", "You have no opengl Driver !",QMessageBox::Ok);
	}


	vs_shader =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	ps_shader =
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);\n"
		"}\n\0";

	compile_shader();


	// set up vertex data (and buffer(s)) and configure vertex attributes
	// ------------------------------------------------------------------
	float vertices[] = {
		 1.0f,  1.0f, 0.0f,  // top right
		 1.0f, -1.0f, 0.0f,  // bottom right
		-1.0f, -1.0f, 0.0f,  // bottom left
		-1.0f,  1.0f, 0.0f   // top left 
	};
	unsigned int indices[] = {  // note that we start from 0!
		0, 1, 3,  // first Triangle
		1, 2, 3   // second Triangle
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Openglwidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.5, 0.5, 0.5, 1);


	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	update();
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

QList<QString> Openglwidget::compile_shader()
{
	QList<QString> errors;

	// build and compile our shader program
	// ------------------------------------
	// vertex shader
	int vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vs_shader, NULL);
	glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	}

	// here we interested in errors
	// fragment shader
	int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &ps_shader, NULL);
	glCompileShader(fragmentShader);
	// check for shader compile errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		//std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		errors.append(infoLog);
	}
	// link shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		//std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		errors.append(infoLog);
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return errors;
}
