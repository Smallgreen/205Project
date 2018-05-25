#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "QString"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QVariant"
#include <iostream>

using namespace std;

class dbmanager
{
public:

    dbmanager(const QString& path);

    void build_table         ();
    void closeDB             ();
    bool create_row          (QString username, QString password, QString type, QString email, int phone);

    void update_username        (QString email, QString username);
    void update_password        (QString username, QString password);
    void update_phone           (QString username, int phone);
    void update_email           (QString username, QString email);

    void printDB();

    //for log in function, check the username and password is correct or not
    bool loginAuthentication(QString uname, QString pword);

    //get user's type (citizen, emer planner or responder)
    QString getType(QString uname, QString pword);


private:

    void generate_sql_queries();
    static int id;

    QString create_cmd;
    QString insert_cmd;
    QString drop_cmd;

    QSqlQuery *sql_query;

    QSqlDatabase u_db;
};

#endif // DBMANAGER_H
