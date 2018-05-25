#include <iostream>
#include "../UI/mainwindow.h"
#include "../UI/logindlg.h"
#include "../database/dbmanager.h"
#include "../database/contactlistdb.h"
#include "../database/msgdb.h"
#include "../database/reportdb.h"
#include <QApplication>
using namespace std;

/**
 * This is the main controller for whole system and demo
 */
int main(int argc, char *argv[])
{
    //initiate user information sqlite
    dbmanager userDB("../userInfo.sqlite");
    userDB.build_table();

    //initiate contact list sqlite
    contactlistDB contactDB("../contactList.sqlite");
    contactDB.build_table();

    //initiate message sqlite
    msgDB msgdb("../message.sqlite");
    msgdb.build_table();

    //initiate reports sqlite
    reportDB rDB("../reports.sqlite");
    rDB.build_table();

    //input prepared user information for demo
    rDB.create_report("a","11:00", "pardee hall", "aasdasdasd");
    rDB.updateVerification(1,true);

    userDB.create_row("a","a","First Responder","person1@laf.edu",1231829);
    userDB.create_row("b","b","Emergency Planner","person1@laf.edu",1231829);
    userDB.create_row("c","c","Citizen","person1@laf.edu",1231829);

    contactDB.addContact("a","b");
    contactDB.addContact("a","c");

    contactDB.addContact("b","a");

    //start displaying ui for three users
    QApplication a(argc, argv);
    MainWindow w;
    w.setDB(&userDB, &contactDB, &msgdb, &rDB);
    w.show();

    MainWindow w2;
    w2.setDB(&userDB, &contactDB, &msgdb, &rDB);
    w2.show();

    MainWindow w3;
    w3.setDB(&userDB, &contactDB, &msgdb, &rDB);
    w3.show();
    return a.exec();


}
