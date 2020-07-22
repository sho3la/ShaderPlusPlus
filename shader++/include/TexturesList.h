#pragma once
#include <QDockWidget>
#include <QMainWindow>
#include <QToolBar>
#include <QAction>

class TexturesList : public QDockWidget
{
public:
	TexturesList(const QString &title, QWidget *parent = nullptr);

	~TexturesList();

private:
	QMainWindow* m_window;
	QToolBar* m_toolbar;
	QAction* newTextureAct;
};