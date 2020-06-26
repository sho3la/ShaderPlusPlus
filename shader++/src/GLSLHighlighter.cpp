#include <GLSLHighlighter.h>
#include <Language.h>
#include <SyntaxStyle.h>

#include <QFile>
#include <QDebug>


GLSLHighlighter::GLSLHighlighter(QTextDocument* document) :
	StyleSyntaxHighlighter(document),
	m_highlightRules(),
	m_includePattern(QRegularExpression(R"(#include\s+([<"][a-zA-Z0-9*._]+[">]))")),
	m_functionPattern(QRegularExpression(R"(\b([A-Za-z0-9_]+(?:\s+|::))*([A-Za-z0-9_]+)(?=\())")),
	m_defTypePattern(QRegularExpression(R"(\b([A-Za-z0-9_]+)\s+[A-Za-z]{1}[A-Za-z0-9_]+\s*[;=])")),
	m_commentStartPattern(QRegularExpression(R"(/\*)")),
	m_commentEndPattern(QRegularExpression(R"(\*/)"))
{
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
		for (auto&& name : names)
		{
			m_highlightRules.append({
				QRegularExpression(QString(R"(\b%1\b)").arg(name)),
				key
				});
		}
	}

	// Following rules has higher priority to display
	// than language specific keys
	// So they must be applied at last.
	// Numbers
	m_highlightRules.append({
		QRegularExpression(R"(\b(0b|0x){0,1}[\d.']+\b)"),
		"Number"
		});

	// Define
	m_highlightRules.append({
		QRegularExpression(R"(#[a-zA-Z_]+)"),
		"Preprocessor"
		});

	// Single line
	m_highlightRules.append({
		QRegularExpression("//[^\n]*"),
		"Comment"
		});
}

void GLSLHighlighter::highlightBlock(const QString& text)
{

	{
		auto matchIterator = m_includePattern.globalMatch(text);

		while (matchIterator.hasNext())
		{
			auto match = matchIterator.next();

			setFormat(
				match.capturedStart(),
				match.capturedLength(),
				syntaxStyle()->getFormat("Preprocessor")
			);

			setFormat(
				match.capturedStart(1),
				match.capturedLength(1),
				syntaxStyle()->getFormat("String")
			);
		}
	}

	// Checking for function
	{
		auto matchIterator = m_functionPattern.globalMatch(text);

		while (matchIterator.hasNext())
		{
			auto match = matchIterator.next();

			setFormat(
				match.capturedStart(),
				match.capturedLength(),
				syntaxStyle()->getFormat("Type")
			);

			setFormat(
				match.capturedStart(2),
				match.capturedLength(2),
				syntaxStyle()->getFormat("Function")
			);
		}
	}

	for (auto& rule : m_highlightRules)
	{
		auto matchIterator = rule.pattern.globalMatch(text);

		while (matchIterator.hasNext())
		{
			auto match = matchIterator.next();

			setFormat(
				match.capturedStart(),
				match.capturedLength(),
				syntaxStyle()->getFormat(rule.formatName)
			);
		}
	}

	setCurrentBlockState(0);

	int startIndex = 0;
	if (previousBlockState() != 1)
	{
		startIndex = text.indexOf(m_commentStartPattern);
	}

	while (startIndex >= 0)
	{
		auto match = m_commentEndPattern.match(text, startIndex);

		int endIndex = match.capturedStart();
		int commentLength = 0;

		if (endIndex == -1)
		{
			setCurrentBlockState(1);
			commentLength = text.length() - startIndex;
		}
		else
		{
			commentLength = endIndex - startIndex + match.capturedLength();
		}

		setFormat(
			startIndex,
			commentLength,
			syntaxStyle()->getFormat("Comment")
		);
		startIndex = text.indexOf(m_commentStartPattern, startIndex + commentLength);
	}
}
