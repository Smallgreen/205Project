#ifndef REGISTERDLG_H
#define REGISTERDLG_H
#include "../database/dbmanager.h"

#include <QDialog>

namespace Ui {
class RegisterDlg;
}

class RegisterDlg : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDlg(QWidget *parent = 0);
    ~RegisterDlg();
    dbmanager *dbm;

private slots:
    void on_regBtn_clicked();

private:
    Ui::RegisterDlg *ui;

};

#endif // REGISTERDLG_H
