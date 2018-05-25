#ifndef REPORTDLG_H
#define REPORTDLG_H

#include "../database/reportdb.h"
#include <QDialog>

namespace Ui {
class reportDlg;
}

class reportDlg : public QDialog
{
    Q_OBJECT

public:
    explicit reportDlg(QWidget *parent = 0);
    ~reportDlg();
    reportDB *rdbm;
    QString user;

private slots:
    void on_sendBtn_clicked();

private:
    Ui::reportDlg *ui;
};

#endif // REPORTDLG_H
