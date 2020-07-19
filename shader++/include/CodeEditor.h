#pragma once
#include <QTextEdit>

class QCompleter;
class LineNumberArea;
class SyntaxStyle;
class StyleSyntaxHighlighter;
class FramedTextAttribute;

class CodeEditor : public QTextEdit
{
	Q_OBJECT

public:
	CodeEditor(QWidget* widget = nullptr);

	~CodeEditor();

	int getFirstVisibleBlock();

	QList<int> getFunctionBlocks();

	void setHighlighter(StyleSyntaxHighlighter* highlighter);

	void setSyntaxStyle(SyntaxStyle* style);

	void setAutoParentheses(bool enabled);

	bool autoParentheses() const;

	void setTabReplace(bool enabled);

	bool tabReplace() const;

	void setTabReplaceSize(int val);

	int tabReplaceSize() const;

	void setAutoIndentation(bool enabled);

	bool autoIndentation() const;

	void setCompleter(QCompleter* completer);

	QCompleter* completer() const;

public Q_SLOTS:

	void insertCompletion(QString s);

	void updateLineNumberAreaWidth(int);

	void updateLineNumberArea(const QRect& rect);

	void updateExtraSelection();

	void updateStyle();

	void onSelectionChanged();

protected:
	void insertFromMimeData(const QMimeData* source) override;

	void paintEvent(QPaintEvent* e) override;

	void resizeEvent(QResizeEvent* e) override;

	void keyPressEvent(QKeyEvent* e) override;

	void focusInEvent(QFocusEvent *e) override;

private:

	void initDocumentLayoutHandlers();

	void initFont();

	void performConnections();

	void handleSelectionQuery(QTextCursor cursor);

	void updateLineGeometry();

	bool proceedCompleterBegin(QKeyEvent *e);

	void proceedCompleterEnd(QKeyEvent* e);

	QChar charUnderCursor(int offset = 0) const;

	QString wordUnderCursor() const;

	void highlightCurrentLine(QList<QTextEdit::ExtraSelection>& extraSelection);

	void highlightParenthesis(QList<QTextEdit::ExtraSelection>& extraSelection);

	bool highlightFunctionBlock(QList<QTextEdit::ExtraSelection>& extraSelection);

	int getIndentationSpaces();

	StyleSyntaxHighlighter* m_highlighter;
	SyntaxStyle* m_syntaxStyle;
	LineNumberArea* m_lineNumberArea;
	QCompleter* m_completer;

	bool m_autoIndentation;
	bool m_autoParentheses;
	bool m_replaceTab;
	QString m_tabReplace;
};
