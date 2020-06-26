#pragma once
#include <QRegularExpression>
#include <QVector>

#include <StyleSyntaxHighlighter.h>
#include <HighlightRule.h>

class SyntaxStyle;

class GLSLHighlighter : public StyleSyntaxHighlighter
{
	Q_OBJECT

public:
	GLSLHighlighter(QTextDocument* document = nullptr);

	~GLSLHighlighter();

protected:
	void highlightBlock(const QString& text) override;

private:

	QVector<HighlightRule> m_highlightRules;

	QRegularExpression m_includePattern;
	QRegularExpression m_functionPattern;
	QRegularExpression m_defTypePattern;

	QRegularExpression m_commentStartPattern;
	QRegularExpression m_commentEndPattern;
};