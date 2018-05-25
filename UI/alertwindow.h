#ifndef ALERTWINDOW_H
#define ALERTWINDOW_H
#include "../database/reportdb.h"
#include <QMainWindow>

namespace Ui {
class AlertWindow;
}

class AlertWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AlertWindow(QWidget *parent = 0);
    ~AlertWindow();
    reportDB *rdbm;
    void displayList();

private slots:
    void on_sendBtn_clicked();

private:
    Ui::AlertWindow *ui;
};

#endif // ALERTWINDOW_H
