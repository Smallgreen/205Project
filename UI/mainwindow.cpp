#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindlg.h"
#include "registerdlg.h"
#include "../database/dbmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setDB(dbmanager *db, contactlistDB *cdb, msgDB *mdb, reportDB *rdb){
    r.dbm = db;
    l.dbm = db;

    mainf.cdbm = cdb;
    mainf.mdbm = mdb;

    maine.cdbm = cdb;
    maine.mdbm = mdb;

    mainf.rdbm = rdb;
    maine.rdbm = rdb;
    mainc.rdbm = rdb;

}


void MainWindow::on_loginBtn_clicked()
{

    l.show();
    if(l.exec() == QDialog::Accepted){
        std::cout << l.usertype.toStdString() << std::endl;
        if(l.usertype == "First Responder"){
            mainf.user = l.username;
            mainf.show();
        }
        else if(l.usertype == "Emergency Planner"){
            maine.user = l.username;
            maine.show();
        }
        else if(l.usertype == "Citizen"){
            mainc.user = l.username;
            mainc.show();
        }
    }
    QWidget::close();
}

void MainWindow::on_regBtn_clicked()
{
    r.show();
    if(r.exec() == QDialog::Accepted){
        on_loginBtn_clicked();
    }
}
