#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QWidget(parent),
     m_view(new QWebEngineView(this))
{
    QWebEnginePage *page = m_view->page();
    page->load(QUrl(QStringLiteral("https://maps.google.com")));
}

Map::~Map()
{
    delete m_view;
}
