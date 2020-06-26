#pragma once
#include <QObject>
#include <QMap>
#include <QString>
#include <QTextCharFormat> // provides formatting information for characters in a QTextDocument

// this class describe Qt style parser for Editor
class SyntaxStyle : public QObject
{
public:
	SyntaxStyle(QObject* parent = nullptr);

	~SyntaxStyle();

	bool load(QString fl);

	QString name() const;

	bool isLoaded() const;

	QTextCharFormat getFormat(QString name) const;

	static SyntaxStyle* defaultStyle();

private:

	bool m_loaded;
	QString m_name;
	QMap<QString,QTextCharFormat> m_data;
};