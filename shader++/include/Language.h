#pragma once
#include <QObject>
#include <QString>
#include <QMap>

class QIODevice;

// this class for parsing language file
class Language : public QObject
{
public:
	Language(QIODevice* device = nullptr, QObject* parent = nullptr);

	~Language();

	bool load(QIODevice* device);

	QStringList keys();

	QStringList names(const QString& key);

	bool isLoaded() const;

private:

	bool m_loaded;
	QMap<QString,QStringList> m_list;
};