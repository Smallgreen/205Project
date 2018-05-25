#include "contactlistdb.h"

int contactlistDB::id = 1;

/**
 * @brief contactlistDB::contactlistDB
 * @param path
 */
contactlistDB::contactlistDB(const QString& path)
{
    generate_sql_queries();

    // create/open the database
    c_db = QSqlDatabase::addDatabase("QSQLITE", "c_db");
    c_db.setDatabaseName(path);

    if (!c_db.open()) {

        std::cerr << "Error: database connection failed"
                  << std::endl;
        exit(0);  // abort program
    } else {

        std::cout  << "Database: connection ok"
                   << std::endl;
    }

}

/**
 * @brief contactlistDB::generate_sql_queries
 */
void contactlistDB::generate_sql_queries() {

    create_cmd += "create table contactListDB ";
    create_cmd += "( id INT NOT NULL UNIQUE, owner QSTRING NOT NULL, contact QSTRING NOT NULL);";

    insert_cmd += "INSERT INTO contactListDB (id, owner, contact) ";
    insert_cmd += "VALUES (:id, :owner, :contact);";

    drop_cmd   += "DROP TABLE IF EXISTS contactListDB;";

    sql_query = nullptr;
}

/**
 * @brief contactlistDB::build_table
 */
void contactlistDB::build_table() {

    sql_query = new QSqlQuery(c_db);

    sql_query->exec(drop_cmd);   // drop existing table

    sql_query->exec(create_cmd); // create table

    delete sql_query;
}

bool contactlistDB::addContact(QString owner, QString contact){
    if(searchContact(owner,contact)){
        return false;
    }
    sql_query = new QSqlQuery(c_db);
    sql_query->prepare(insert_cmd);

    sql_query->bindValue(":id",    id   );
    sql_query->bindValue(":owner", owner);
    sql_query->bindValue(":contact", contact);

    if(sql_query->exec()){
        std::cout  << "added" << std::endl;
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
 * @brief search for contact with given username
 * @param owner
 * @param contact
 * @return
 */
bool contactlistDB::searchContact(QString owner, QString contact){
    QString find_cmd = "SELECT id, owner, contact FROM contactListDB WHERE owner = :owner and contact = :contact;";
    sql_query = new QSqlQuery(c_db);
    sql_query->prepare(find_cmd);
    sql_query->bindValue(":owner", owner);
    sql_query->bindValue(":contact", contact);
    sql_query->exec();

    if(sql_query->next()){
        //int id = sql_query->value(0).toInt();
        QString owner = sql_query->value(1).toString();
        QString contact = sql_query->value(2).toString();

        return true;
    }
    else return false;
}

/**
 * @brief get contact list for certain user
 * @param owner
 * @return
 */
QStringList contactlistDB::getList(QString owner){
    QStringList contactList;

    QString find_cmd = "SELECT id, owner, contact FROM contactListDB WHERE owner = :owner;";
    sql_query = new QSqlQuery(c_db);
    sql_query->prepare(find_cmd);
    sql_query->bindValue(":owner", owner);
    sql_query->exec();

    while(sql_query->next()){
        //int id = sql_query->value(0).toInt();
        QString owner = sql_query->value(1).toString();
        QString contact = sql_query->value(2).toString();

        contactList << contact;
    }
    return contactList;
}
