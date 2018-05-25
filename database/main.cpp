#include <iostream>
#include "dbmanager.h"
#include "contactlistdb.h"
#include "reportdb.h"
#include "msgdb.h"

using namespace std;

int main()
{
    //for testing
//    dbmanager dbm("../userInfoDB/test.sqlite");
//    dbm.build_table();

//        dbm.create_row("person0","aaaa","citizen","person1@laf.edu",1231829);
//        dbm.create_row("person1","aaaa","First Responder","person2@laf.edu",1231829);
//        dbm.create_row("person2","aaaa","emergencyPlanner","person3@laf.edu",1231829);
//    dbm.printDB();

//    dbm.getType("person1","aaaa");

//    contactlistDB cdb("../contactList.sqlite");
//    cdb.build_table();
//    cdb.addContact("person0","person2");
//    cdb.addContact("person1","person0");
//    cdb.addContact("person0","person1");

//    cout<< cdb.searchContact("person1","person0") <<endl;

//    cdb.getList("person0");

//    dbm.loginAuthentication("person0", "aaaa");

//    dbm.update_username("person1@laf.edu", "person00");
//    dbm.update_password("person1", "person01");
//    dbm.update_phone("person00", 121);
//    dbm.update_email("person2", "2344@lehigh.edu");
//    dbm.printDB();

    //dbm.closeDB();

    reportDB rdb("../reportDB.sqlite");
    rdb.build_table();
    rdb.create_report("a","123","asd","asdasd");
    rdb.reportList();
    rdb.sendAlert(1);
    std::cout << '?' << endl;
    rdb.reportList();
    std::cout << '?' << endl;
    rdb.getUnveriAlerts();
    rdb.updateVerification(1, true);
    //rdb.updateVerified(1);
    rdb.getUnveriAlerts();

    rdb.getVerifiedAlert();

//    msgDB mdb("../test.sqlite");
//    mdb.build_table();
//    mdb.create_msg("a","b","aaa");
//    mdb.receive_msg("b");

    return 0;
}
