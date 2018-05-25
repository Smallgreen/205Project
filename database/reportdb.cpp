#include "reportdb.h"

int reportDB::id = 1;

/**
 * @brief reportDB::reportDB
 * @param path
 */
reportDB::reportDB(const QString& path)
{
    generate_sql_queries();

    // create/open the database
    r_db = QSqlDatabase::addDatabase("QSQLITE","r_db");
    r_db.setDatabaseName(path);

    if (!r_db.open()) {

        std::cerr << "Error: database connection failed"
                  << std::endl;
        exit(0);  // abort program
    } else {

        std::cout  << "Database: connection ok"
                   << std::endl;
    }

}

/**
 * @brief reportDB::generate_sql_queries
 */
void reportDB::generate_sql_queries() {

    //bool verified, bool 1isNews/0isReport, int count
    //QString sender, QString time, QString location, QString detail

    create_cmd += "create table reportDB ";
    create_cmd += "( id INT NOT NULL UNIQUE, sender QSTRING NOT NULL, time QSTRING NOT NULL, location QSTRING NOT NULL, detail QSTRING NOT NULL, verified BOOL NOT NULL, isNews BOOL NOT NULL, vcount INT NOT NULL, dcount INT NOT NULL);";

    insert_cmd += "INSERT INTO reportDB (id, sender, time, location, detail, verified, isNews, vcount, dcount) ";
    insert_cmd += "VALUES (:id, :sender, :time, :location, :detail, :verified, :isNews, :vcount, :dcount);";

    drop_cmd   += "DROP TABLE IF EXISTS reportDB;";

    sql_query = nullptr;
}

/**
 * @brief reportDB::build_table
 */
void reportDB::build_table() {

    sql_query = new QSqlQuery(r_db);

    sql_query->exec(drop_cmd);   // drop existing table

    sql_query->exec(create_cmd); // create table

    delete sql_query;
}


/**
 * @brief reportDB::create_report
 * @param sender
 * @param time
 * @param location
 * @param detail
 * @return
 */
bool reportDB::create_report(QString sender, QString time, QString location, QString detail){
    sql_query = new QSqlQuery(r_db);
    sql_query->prepare(insert_cmd);

    //:id, :sender, :time, :location, :detail, :verified, :isNews, :count
    sql_query->bindValue(":id",    id   );
    sql_query->bindValue(":sender", sender);
    sql_query->bindValue(":time", time);
    sql_query->bindValue(":location", location);
    sql_query->bindValue(":detail", detail);
    sql_query->bindValue(":verified", false);
    sql_query->bindValue(":isNews", false);
    sql_query->bindValue(":vcount", 0);
    sql_query->bindValue(":dcount", 0);

    if(sql_query->exec()){
        id++;
        delete sql_query;
        return true;

    }
    else{
        delete sql_query;
        return false;
    }
}


/**
 * @brief reportDB::reportList
 * @return
 */
QStringList reportDB::reportList(){
    QStringList reportList;

    QString find_cmd = "SELECT id, sender, time, location, detail, isNews FROM reportDB WHERE isNews = :isNews;";
    sql_query = new QSqlQuery(r_db);
    sql_query->prepare(find_cmd);
    sql_query->bindValue(":isNews", false);
    sql_query->exec();

    while(sql_query->next()){
        int id = sql_query->value(0).toInt();
        QString sender = sql_query->value(1).toString();
        QString time = sql_query->value(2).toString();
        QString loc = sql_query->value(3).toString();
        QString detail = sql_query->value(4).toString();

        QString report;
        report.append(id);
        //, " ",sender, " ",time, " ",loc, " ",detail, "\n"
        report.append(sender);
        report.append(" ");
        report.append(time);
        report.append(" ");
        report.append(loc);
        report.append("\n");
        report.append("   detail:");
        report.append(detail);
        report.append("\n");

        reportList << report;

        std::cout << id
                  << "  "
                  << sql_query->value(5).toString().toStdString()
                  << std::endl;
    }
    return reportList;
}

/**
 * @brief reportDB::sendAlert
 * @param id
 */
void reportDB::sendAlert(int id){
    QString update_cmd;

    update_cmd += "UPDATE reportDB ";
    update_cmd += "SET isNews = :isNews ";
    update_cmd += "WHERE id = :id;";

    sql_query = new QSqlQuery(r_db);

    sql_query->prepare(update_cmd);

    sql_query->bindValue(":id",    id);

    sql_query->bindValue(":isNews",    true);

    sql_query->exec();

    delete sql_query;
}

/**
 * @brief reportDB::getVerifiedAlert
 * @return
 */
QStringList reportDB::getVerifiedAlert(){
    QStringList reportList;

    QString find_cmd = "SELECT id, time, location, detail, verified FROM reportDB WHERE verified = :verified;";
    sql_query = new QSqlQuery(r_db);
    sql_query->prepare(find_cmd);
    sql_query->bindValue(":verified", true);
    sql_query->exec();

    while(sql_query->next()){
        QString id = QString::number(sql_query->value(0).toInt());
        QString time = sql_query->value(1).toString();
        QString loc = sql_query->value(2).toString();
        QString detail = sql_query->value(3).toString();

        QString report;
        report.append(id);
        report.append(" ");
        //, " ",sender, " ",time, " ",loc, " ",detail, "\n"
        report.append(time);
        report.append(" ");
        report.append(loc);
        report.append("\n");
        report.append("   detail:");
        report.append(detail);
        report.append("\n");

        reportList << report;

        std::cout << report.toStdString()
                  << std::endl;
    }
    return reportList;
}

/**
 * @brief reportDB::getUnveriAlerts
 * @return
 */
QStringList reportDB::getUnveriAlerts(){
    QStringList reportList;

    QString find_cmd = "SELECT id, time, location, detail, verified FROM reportDB WHERE verified = :verified;";
    sql_query = new QSqlQuery(r_db);
    sql_query->prepare(find_cmd);
    sql_query->bindValue(":verified", false);
    sql_query->exec();

    while(sql_query->next()){
        QString id = QString::number(sql_query->value(0).toInt());
        QString time = sql_query->value(1).toString();
        QString loc = sql_query->value(2).toString();
        QString detail = sql_query->value(3).toString();

        QString report;
        report.append(id);
        report.append(" ");
        //, " ",sender, " ",time, " ",loc, " ",detail, "\n"
        report.append(time);
        report.append(" ");
        report.append(loc);
        report.append("\n");
        report.append("   detail:");
        report.append(detail);
        report.append("\n");

        reportList << report;

        std::cout << report.toStdString()
                  << std::endl;
    }
    return reportList;
}

/**
 * @brief reportDB::getNews
 * @return
 */
QStringList reportDB::getNews(){
    QStringList reportList;

    QString find_cmd = "SELECT id, time, location, detail, isNews, verified FROM reportDB WHERE isNews = :isNews and verified = :verified;";
    sql_query = new QSqlQuery(r_db);
    sql_query->prepare(find_cmd);
    sql_query->bindValue(":isNews", true);
    sql_query->bindValue(":verified", false);
    sql_query->exec();

    while(sql_query->next()){
        QString id = QString::number(sql_query->value(0).toInt());
        QString time = sql_query->value(1).toString();
        QString loc = sql_query->value(2).toString();
        QString detail = sql_query->value(3).toString();

        QString report;
        report.append(id);
        report.append(" ");
        //, " ",sender, " ",time, " ",loc, " ",detail, "\n"
        report.append(time);
        report.append(" ");
        report.append(loc);
        report.append("\n");
        report.append("   detail:");
        report.append(detail);
        report.append("\n");

        reportList << report;

        std::cout << report.toStdString()
                  << std::endl;
    }
    return reportList;
}

/**
 * @brief reportDB::updateVerification
 * @param id
 * @param verify
 */
void reportDB::updateVerification(int id, bool verify){

    if(verify){

        updateVcount(id);
    }
    else{
        updateDcount(id);
    }

    std::cout << "v "<< std::endl;
}

/**
 * @brief reportDB::updateVcount
 * @param id
 */
void reportDB::updateVcount(int id){

    int vcount;
    QString find_cmd = "SELECT id, vcount FROM reportDB WHERE id = :id;";
    sql_query = new QSqlQuery(r_db);
    sql_query->prepare(find_cmd);
    sql_query->bindValue(":id", id);
    sql_query->exec();
    if(sql_query->first()){
        vcount = sql_query->value(1).toInt();
    }
    delete sql_query;
    vcount++;

    QString update_cmd;

    update_cmd += "UPDATE reportDB ";
    update_cmd += "SET vcount = :vcount ";
    update_cmd += "WHERE id = :id;";

    sql_query = new QSqlQuery(r_db);

    sql_query->prepare(update_cmd);

    sql_query->bindValue(":id",    id);

    sql_query->bindValue(":vcount",    vcount);

    sql_query->exec();

    delete sql_query;

    //set threshold
    if(vcount > 0){
        updateVerified(id);
    }
}

/**
 * @brief reportDB::updateDcount
 * @param id
 */
void reportDB::updateDcount(int id){
    int dcount;

    QString find_cmd = "SELECT id, dcount FROM reportDB WHERE id = :id;";
    sql_query = new QSqlQuery(r_db);
    sql_query->prepare(find_cmd);
    sql_query->bindValue(":id", id);
    sql_query->exec();
    if(sql_query->first()){
    dcount = sql_query->value(1).toInt();
    }
    delete sql_query;
    dcount++;

    QString update_cmd;

    update_cmd += "UPDATE reportDB ";
    update_cmd += "SET dcount = :dcount ";
    update_cmd += "WHERE id = :id;";

    sql_query = new QSqlQuery(r_db);

    sql_query->prepare(update_cmd);

    sql_query->bindValue(":id",    id);

    sql_query->bindValue(":dcount",    dcount);

    sql_query->exec();

    delete sql_query;
}

/**
 * @brief reportDB::updateVerified
 * @param id
 */
void reportDB::updateVerified(int id){
    QString update_cmd;

    update_cmd += "UPDATE reportDB ";
    update_cmd += "SET verified = :verified ";
    update_cmd += "WHERE id = :id;";

    sql_query = new QSqlQuery(r_db);

    sql_query->prepare(update_cmd);

    sql_query->bindValue(":id",    id);

    sql_query->bindValue(":verified",    true);

    sql_query->exec();

    delete sql_query;
}

