#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H
#include "../database/contactlistdb.h"
#include "../database/msgdb.h"
#include "messagedlg.h"

#include <QMainWindow>

namespace Ui {
class messageWindow;
}

class messageWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit messageWindow(QWidget *parent = 0);
    ~messageWindow();
    contactlistDB *cdbm;
    msgDB *mdbm;

    QString owner;
    messageDlg mdlg;

    void displayList();

private slots:
    void on_searchBtn_clicked();

    void on_addCBtn_clicked();

    void on_msgBtn_clicked();

    void on_unreadBtn_clicked();

private:
    Ui::messageWindow *ui;
};

#endif // MESSAGEWINDOW_H
