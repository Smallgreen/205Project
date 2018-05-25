#include "messagedlg.h"
#include "ui_messagedlg.h"

messageDlg::messageDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::messageDlg)
{
    ui->setupUi(this);
}

messageDlg::~messageDlg()
{
    delete ui;
}

void messageDlg::on_sendBtn_clicked()
{
    mdbm->create_msg(sender, rcv, ui->contentEdit->toPlainText());
    QDialog::close();
}

void messageDlg::setRcver(QString rcver){
    ui->rcvBrowser->setText(rcver);
    rcv = rcver;
}
