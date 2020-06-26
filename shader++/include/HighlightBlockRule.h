#pragma once
#include <QRegularExpression>
#include <QString>

struct HighlightBlockRule
{
	HighlightBlockRule() : startPattern(),endPattern(),formatName(){}

	HighlightBlockRule(QRegularExpression start, QRegularExpression end, QString format) :
		startPattern(std::move(start)),endPattern(std::move(end)),formatName(std::move(format)) {}

	QRegularExpression startPattern;
	QRegularExpression endPattern;
	QString formatName;
};