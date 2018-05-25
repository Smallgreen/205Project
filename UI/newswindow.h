#ifndef NEWSWINDOW_H
#define NEWSWINDOW_H
#include "verifywindow.h"
#include <QMainWindow>
#include "../database/reportdb.h"


namespace Ui {
class NewsWindow;
}

class NewsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NewsWindow(QWidget *parent = 0);
    ~NewsWindow();
    VerifyWindow vw;
    reportDB *rdbm;
    void displayList();

private slots:

    void on_refreshBtn_clicked();
    void on_verifyBtn_clicked();

private:
    Ui::NewsWindow *ui;
};

#endif // NEWSWINDOW_H
