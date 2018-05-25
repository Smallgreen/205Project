#ifndef MSGDB_H
#define MSGDB_H
#include "QString"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QVariant"
#include <iostream>

using namespace std;

class msgDB
{
public:

    msgDB(const QString& path);


    void build_table();

    //create new message
    bool create_msg(QString sender, QString receiver, QString message);

    //return message content
    QString receive_msg(QString receiver);

    //check the status of message is read or not
    void updateRead(int id);

    void printDB();
    static int id;

private:

    void generate_sql_queries();

    QString create_cmd;
    QString insert_cmd;
    QString drop_cmd;

    QSqlQuery *sql_query;

    QSqlDatabase m_db;
};

#endif // MSGDB_H
