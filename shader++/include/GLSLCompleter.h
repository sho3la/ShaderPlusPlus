#pragma once
#include <QCompleter>

class GLSLCompleter : public QCompleter
{
	Q_OBJECT

public:
	GLSLCompleter(QObject* parent = nullptr);

	~GLSLCompleter();
};