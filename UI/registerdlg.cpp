#include "registerdlg.h"
#include "ui_registerdlg.h"
#include "../database/dbmanager.h"
#include "logindlg.h"

RegisterDlg::RegisterDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDlg)
{
    ui->setupUi(this);

}

RegisterDlg::~RegisterDlg()
{
    delete ui;
}

void RegisterDlg::on_regBtn_clicked()
{
    //dbmanager *dbm
    //dbmanager userDBR("../userInfo.sqlite");

    QString username = ui->unameEdit->text();
    QString password = ui->pwdEdit->text();
    QString email = ui->emailEdit->text();
    QString phone = ui->phoneEdit->text();
    QString type = ui->comboBox->currentText();

    //(QString username, QString password, QString type, QString email, int phone)
    dbm->create_row(username, password, type, email, phone.toInt());
    //dbm->printDB();

    accept();

}
