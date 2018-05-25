#include "verifywindow.h"
#include "ui_verifywindow.h"
#include <QMessageBox>

VerifyWindow::VerifyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VerifyWindow)
{
    ui->setupUi(this);
}

VerifyWindow::~VerifyWindow()
{
    delete ui;
}

void VerifyWindow::on_verBtn_clicked()
{
    rdbm->updateVerification(ui->idEdit->text().toInt(), true);
    QMessageBox::information(this, tr("success"), tr("verification is accepted"), QMessageBox::Yes);
    ui->idEdit->setText("");
    displayList();
}

void VerifyWindow::on_denyBtn_clicked()
{
    rdbm->updateVerification(ui->idEdit->text().toInt(), false);
    QMessageBox::information(this, tr("success"), tr("verification is accepted"), QMessageBox::Yes);
    ui->idEdit->setText("");
    displayList();
}

void VerifyWindow::displayList(){
    ui->detBrowser->setText("");
    QStringList rList = rdbm->getNews();
    foreach(QString r, rList){
        ui->detBrowser->append(r);
    }
}
