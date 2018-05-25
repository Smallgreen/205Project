#include "mainwindow.h"
#include <iostream>
#include "logindlg.h"
#include <QApplication>
#include "../database/dbmanager.h"

int main(int argc, char *argv[])
{
    dbmanager userDB("../userInfo.sqlite");
    userDB.build_table();

    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();


        return a.exec();

//    if(logdlg.exec() == QDialog::Accepted){
//        logwin.show();
//        return a.exec();
//    }


}
