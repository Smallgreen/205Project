#include "messagewindow.h"
#include "ui_messagewindow.h"
#include <QMessageBox>
#include <QStringList>
#include <qstring.h>

messageWindow::messageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::messageWindow)
{
    ui->setupUi(this);
}

messageWindow::~messageWindow()
{
    delete ui;
}

void messageWindow::on_searchBtn_clicked()
{
    if(ui->searchEdit->text().isEmpty()){
        QMessageBox::warning(this, tr("warning"), tr("please fill in user name"), QMessageBox::Yes);
    }
    else{

        if(cdbm->searchContact(owner, ui->searchEdit->text())){
            ui->contactMsgEdit->setText(ui->searchEdit->text());
        }
        else{
            QMessageBox::warning(this, tr("error"), tr("contact is not found"), QMessageBox::Yes);
        }
    }

}

void messageWindow::on_addCBtn_clicked()
{
    if(ui->addEdit->text().isEmpty()){
        QMessageBox::warning(this, tr("warning"), tr("please fill in user name"), QMessageBox::Yes);
    }
    else{

        if(cdbm->addContact(owner, ui->addEdit->text())){
            QMessageBox::information(this, tr("success"), tr("contact is added"), QMessageBox::Yes);
            ui->contactList->append(ui->addEdit->text());
            ui->addEdit->setText("");
        }
        else{
            QMessageBox::warning(this, tr("error"), tr("contact is already added"), QMessageBox::Yes);
        }
    }
}

void messageWindow::on_msgBtn_clicked()
{
    if(ui->contactMsgEdit->text().isEmpty()){
        QMessageBox::warning(this, tr("error"), tr("please fill in contact"), QMessageBox::Yes);
    }
    else{
        mdlg.show();
        mdlg.setRcver(ui->contactMsgEdit->text());
        mdlg.mdbm = mdbm;
        mdlg.sender = owner;
    }
}

void messageWindow::displayList(){

        QStringList cList = cdbm->getList(owner);
        foreach(QString c, cList){
            ui->contactList->append(c);
        }

}

void messageWindow::on_unreadBtn_clicked()
{
    QString newMsg = mdbm->receive_msg(owner);
    if(newMsg == NULL){
        QMessageBox::warning(this, tr("new message"), tr("no new message"), QMessageBox::Yes);

    }
     else {
        //std::cout << mdbm->receive_msg(owner).toStdString() << std::endl;
        QMessageBox::information(this, tr("new message"), newMsg, QMessageBox::Yes);
    }
}
