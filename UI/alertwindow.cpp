#include "alertwindow.h"
#include "ui_alertwindow.h"
#include <QMessageBox>

AlertWindow::AlertWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AlertWindow)
{
    ui->setupUi(this);
}

AlertWindow::~AlertWindow()
{
    delete ui;
}

void AlertWindow::on_sendBtn_clicked()
{
    rdbm->sendAlert(ui->idEdit->text().toInt());
    QMessageBox::information(this, tr("success"), tr("alert is sent"), QMessageBox::Yes);
    ui->idEdit->setText("");
    displayList();
}

void AlertWindow::displayList()
{
    ui->reportBrowser->setText("");
    QStringList rList = rdbm->getUnveriAlerts();
    foreach(QString r, rList){
        ui->reportBrowser->append(r);
    }
}
