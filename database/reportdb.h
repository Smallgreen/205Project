#ifndef REPORTDB_H
#define REPORTDB_H
#include "QString"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QVariant"
#include <iostream>

class reportDB
{
public:
    reportDB(const QString& path);
    void build_table();
    static int id;

    bool create_report(QString sender, QString time, QString location, QString detail);

    QStringList reportList();//id, sender, time, location, detail
    void sendAlert(int id);//set isNews

    QStringList getVerifiedAlert();//return select verified news
    QStringList getUnveriAlerts();//return select unverified news

    QStringList getNews();
    void updateVerification(int id, bool verify);//update when everytime click

    void updateVerified(int id);//update when everytime click
    void updateVcount(int id);
    void updateDcount(int id);


private:

    void generate_sql_queries();

    QString create_cmd;
    QString insert_cmd;
    QString drop_cmd;

    QSqlQuery *sql_query;

    QSqlDatabase r_db;

};

#endif // REPORTDB_H
