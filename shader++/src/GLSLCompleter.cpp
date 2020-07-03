#include "GLSLCompleter.h"
#include "Language.h"

#include <QStringListModel>
#include <QFile>

GLSLCompleter::GLSLCompleter(QObject *parent) : QCompleter(parent)
{
	// Setting up GLSL types
	QStringList list;

	Q_INIT_RESOURCE(shaderPlusPlus_resources);
	QFile fl(":/languages/glsl.xml");

	if (!fl.open(QIODevice::ReadOnly))
	{
		return;
	}

	Language language(&fl);

	if (!language.isLoaded())
	{
		return;
	}

	auto keys = language.keys();
	for (auto&& key : keys)
	{
		auto names = language.names(key);
		list.append(names);
	}

	setModel(new QStringListModel(list, this));
	setCompletionColumn(0);
	setModelSorting(QCompleter::CaseInsensitivelySortedModel);
	setCaseSensitivity(Qt::CaseSensitive);
	setWrapAround(true);
}

GLSLCompleter::~GLSLCompleter()
{
}
