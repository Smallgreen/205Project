#ifndef MAIN_EP_H
#define MAIN_EP_H
#include "messagewindow.h"
#include "../database/contactlistdb.h"
#include "../database/msgdb.h"
#include "../database/reportdb.h"
#include <QMainWindow>
#include <QUrl>
#include <QWidget>
#include <QtWebEngineWidgets>
#include "simwindow.h"
#include "alertwindow.h"
#include "newswindow.h"

namespace Ui {
class Main_EP;
}

class Main_EP : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_EP(QWidget *parent = 0);
    ~Main_EP();
    messageWindow mw;
    QString user;
    contactlistDB *cdbm;
    msgDB *mdbm;
    SimWindow sw;
    AlertWindow aw;
    reportDB *rdbm;


private slots:
    void on_msgBtn_clicked();

    void on_SimBtn_clicked();

    void on_repBtn_clicked();

private:
    Ui::Main_EP *ui;
};

#endif // MAIN_EP_H
