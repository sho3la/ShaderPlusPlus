#pragma once
#include <QSyntaxHighlighter>

class SyntaxStyle;

class StyleSyntaxHighlighter : public QSyntaxHighlighter
{
public:
	StyleSyntaxHighlighter(QTextDocument* document = nullptr);

	~StyleSyntaxHighlighter();

	void setSyntaxStyle(SyntaxStyle* style);

	SyntaxStyle* syntaxStyle() const;

private:
	SyntaxStyle* m_syntaxStyle;
};