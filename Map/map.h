#ifndef MAP_H
#define MAP_H
#include <QMainWindow>

#include <QUrl>
#include <QWidget>
#include <QtWebEngineWidgets>
namespace Ui {
class Map;
}



class Map : public QWidget
{
    Q_OBJECT
public:
    explicit Map(QWidget *parent = nullptr);
   ~Map();

private:
    QWebEngineView *m_view;
};

#endif // MAP_H
