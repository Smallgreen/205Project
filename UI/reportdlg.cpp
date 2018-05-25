#include "reportdlg.h"
#include "ui_reportdlg.h"
#include <QMessageBox>

reportDlg::reportDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reportDlg)
{
    ui->setupUi(this);
}

reportDlg::~reportDlg()
{
    delete ui;
}

void reportDlg::on_sendBtn_clicked()
{
    rdbm->create_report(user,ui->timeEdit->text(), ui->locationEdit->text(), ui->detailEdit->toPlainText());
    QMessageBox::information(this, tr("success"), tr("report is sent"), QMessageBox::Yes);
    ui->timeEdit->setText("");
    ui->locationEdit->setText("");
    ui->detailEdit->setText("");

}
