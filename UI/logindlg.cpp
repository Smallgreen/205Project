#include "logindlg.h"
#include "ui_logindlg.h"
#include "../database/dbmanager.h"
#include <QMessageBox>


loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDlg)
{
    ui->setupUi(this);
}

loginDlg::~loginDlg()
{
    delete ui;
}

void loginDlg::on_loginBtn_clicked()
{

    if(ui->unameEdit->text().isEmpty() || ui->pwdEdit->text().isEmpty()){
        QMessageBox::warning(this, tr("warning"), tr("please fill in user name and password"), QMessageBox::Yes);
    }
    else{
        if(dbm->loginAuthentication(ui->unameEdit->text(), ui->pwdEdit->text())){
            usertype = dbm->getType(ui->unameEdit->text(), ui->pwdEdit->text());
            username = ui->unameEdit->text();
            accept();
        }
        else{
            QMessageBox::warning(this, tr("warning"), tr("username or password error"), QMessageBox::Yes);
        }
    }

}
