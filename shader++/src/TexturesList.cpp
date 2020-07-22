#include "TexturesList.h"

TexturesList::TexturesList(const QString &title, QWidget * parent) : QDockWidget(title,parent)
{
	m_window = new QMainWindow();

	m_toolbar = new QToolBar();
	m_toolbar->setMovable(false);
	newTextureAct = new QAction(QIcon(QPixmap(":/icons/new.png")), tr("&New Texture"), this);
	m_toolbar->addAction(newTextureAct);

	m_window->addToolBar(m_toolbar);
	setWidget(m_window);
}

TexturesList::~TexturesList()
{
}
