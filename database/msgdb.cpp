#include "msgdb.h"
int msgDB::id = 0;

/**
 * @brief msgDB::msgDB
 * @param path
 */
msgDB::msgDB(const QString& path) {

    generate_sql_queries();

    // create/open the database
    m_db = QSqlDatabase::addDatabase("QSQLITE","m_db");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {

        std::cerr << "Error: database connection failed"
                  << std::endl;
        exit(0);  // abort program
    } else {

        std::cout  << "Database: connection ok"
                   << std::endl;
    }

}

/**
 * @brief msgDB::generate_sql_queries
 */
void msgDB::generate_sql_queries() {

    create_cmd += "create table messageDB ";
    create_cmd += "( id INT NOT NULL UNIQUE, sender QSTRING NOT NULL, receiver QSTRING NOT NULL, message QSTRING NOT NULL, read BOOL NOT NULL);";

    insert_cmd += "INSERT INTO messageDB (id, sender, receiver, message, read) ";
    insert_cmd += "VALUES (:id, :sender, :receiver, :message, :read);";

    drop_cmd   += "DROP TABLE IF EXISTS messageDB;";

    sql_query = nullptr;
}

/**
 * @brief msgDB::build_table
 */
void msgDB::build_table() {

    sql_query = new QSqlQuery(m_db);

    sql_query->exec(drop_cmd);   // drop existing table

    sql_query->exec(create_cmd); // create table

    delete sql_query;
}

/**
 * @brief msgDB::create_msg
 * @param sender
 * @param receiver
 * @param message
 * @return
 */
bool msgDB::create_msg(QString sender, QString receiver, QString message){
    sql_query = new QSqlQuery(m_db);
    sql_query->prepare(insert_cmd);

    sql_query->bindValue(":id",    id   );
    sql_query->bindValue(":sender", sender);
    sql_query->bindValue(":receiver", receiver);
    sql_query->bindValue(":message", message);
    sql_query->bindValue(":read", false);

    if(sql_query->exec()){
        id++;
        delete sql_query;
        return true;

    }
    else {
        delete sql_query;
        return false;
    }
}

/**
 * @brief msgDB::receive_msg
 * @param receiver
 * @return
 */
QString msgDB::receive_msg(QString receiver){
    QString content;
    QString find_cmd = "SELECT id, sender, receiver, message, read FROM messageDB WHERE receiver = :receiver and read = :read;";
    sql_query = new QSqlQuery(m_db);
    sql_query->prepare(find_cmd);
    sql_query->bindValue(":receiver", receiver);
    sql_query->bindValue(":read", false);
    sql_query->exec();

    if(sql_query->next()){
        content = "From ";
        content.append(sql_query->value(1).toString());
        content.append(":");
        content.append("\n");
        content.append(sql_query->value(3).toString());
        updateRead(sql_query->value(0).toInt());
       // std::cout << "in db" << content.toStdString() << std::endl;
        return content;
    }

    else return NULL;

}

/**
 * @brief msgDB::updateRead
 * @param id
 */
void msgDB::updateRead(int id) {
    QString update_cmd;

    update_cmd += "UPDATE messageDB ";
    update_cmd += "SET read = :read ";
    update_cmd += "WHERE id = :id;";

    sql_query = new QSqlQuery(m_db);

    sql_query->prepare(update_cmd);

    sql_query->bindValue(":id",    id);

    sql_query->bindValue(":read",    true);

    sql_query->exec();

    delete sql_query;
}


