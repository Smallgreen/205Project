#ifndef MESSAGEDLG_H
#define MESSAGEDLG_H
#include "../database/msgdb.h"

#include <QDialog>

namespace Ui {
class messageDlg;
}

class messageDlg : public QDialog
{
    Q_OBJECT

public:
    explicit messageDlg(QWidget *parent = 0);
    ~messageDlg();
    void setRcver(QString rcver);
    msgDB *mdbm;
    QString rcv;
    QString sender;

private slots:
    void on_sendBtn_clicked();

private:
    Ui::messageDlg *ui;
};

#endif // MESSAGEDLG_H
