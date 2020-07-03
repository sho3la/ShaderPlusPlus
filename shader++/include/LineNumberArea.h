#pragma once
#include <QWidget>

class CodeEditor;
class SyntaxStyle;

class LineNumberArea : public QWidget
{
	Q_OBJECT

public:
	LineNumberArea(CodeEditor* parent = nullptr);

	~LineNumberArea();

	QSize sizeHint() const override;

	void setSyntaxStyle(SyntaxStyle* style);

	SyntaxStyle* syntaxStyle() const;

protected:
	void paintEvent(QPaintEvent* event) override;

private:

	SyntaxStyle* m_syntaxStyle;

	CodeEditor* m_codeEditParent;
};