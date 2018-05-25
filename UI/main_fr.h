#ifndef MAIN_FR_H
#define MAIN_FR_H
#include "messagewindow.h"
#include "../database/contactlistdb.h"
#include "../database/msgdb.h"
#include "../database/reportdb.h"
#include <QMainWindow>
#include <QUrl>
#include <QWidget>
#include <QtWebEngineWidgets>
#include "newswindow.h"

namespace Ui {
class Main_FR;
}

class Main_FR : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_FR(QWidget *parent = 0);
    ~Main_FR();
    messageWindow mw;
    QString user;
    contactlistDB *cdbm;
    msgDB *mdbm;
    NewsWindow nw;
    reportDB *rdbm;

private slots:

    void on_msgBtn_clicked();

    void on_newsBtn_clicked();

private:
    Ui::Main_FR *ui;
};

#endif // MAIN_FR_H
