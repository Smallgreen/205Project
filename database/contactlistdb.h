#ifndef CONTACTLISTDB_H
#define CONTACTLISTDB_H

#include "QString"
#include <QStringList>
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QVariant"
#include <iostream>

using namespace std;

class contactlistDB
{
public:

    contactlistDB(const QString& path);

    void build_table();

    //create new contact in form
    bool addContact(QString owner, QString contact);
    //search for contact using username
    bool searchContact(QString owner, QString contact);
    //return contact list of certain user
    QStringList getList(QString owner);

private:

    void generate_sql_queries();
    static int id;
    QString create_cmd;
    QString insert_cmd;
    QString drop_cmd;

    QSqlQuery *sql_query;

    QSqlDatabase c_db;
};

#endif // CONTACTLISTDB_H
