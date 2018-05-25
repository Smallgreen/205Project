#ifndef VERIFYWINDOW_H
#define VERIFYWINDOW_H

#include "../database/reportdb.h"
#include <QMainWindow>

namespace Ui {
class VerifyWindow;
}

class VerifyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VerifyWindow(QWidget *parent = 0);
    ~VerifyWindow();
    reportDB *rdbm;
    void displayList();

private slots:
    void on_verBtn_clicked();

    void on_denyBtn_clicked();

private:
    Ui::VerifyWindow *ui;
};

#endif // VERIFYWINDOW_H
