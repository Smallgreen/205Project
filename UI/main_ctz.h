#ifndef MAIN_CTZ_H
#define MAIN_CTZ_H
#include "messagewindow.h"
#include "../database/contactlistdb.h"
#include "../database/msgdb.h"
#include "../database/reportdb.h"
#include <QMainWindow>
#include <QUrl>
#include <QWidget>
#include <QtWebEngineWidgets>
#include "messagedlg.h"
#include "reportdlg.h"
#include "newswindow.h"


namespace Ui {
class Main_CTZ;
}

class Main_CTZ : public QMainWindow
{
    Q_OBJECT

public:
    explicit Main_CTZ(QWidget *parent = 0);
    ~Main_CTZ();
    QString user;
    messageDlg mdlg;
    reportDlg rdlg;
    NewsWindow nw;

    reportDB *rdbm;

private slots:
    void on_disBtn_clicked();

    void on_repBtn_clicked();

    void on_newsBtn_clicked();

private:
    Ui::Main_CTZ *ui;
};

#endif // MAIN_CTZ_H
