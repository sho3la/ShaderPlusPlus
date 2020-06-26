#pragma once
#include <QRegularExpression>
#include <QString>

struct HighlightRule
{
	HighlightRule() : pattern(), formatName() {}

	HighlightRule(QRegularExpression p, QString f)
		: pattern(std::move(p)), formatName(std::move(f)) {}

	QRegularExpression pattern;
	QString formatName;
};