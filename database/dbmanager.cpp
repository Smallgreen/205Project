#include "dbmanager.h"
int dbmanager::id = 1;

/**
 * @brief dbmanager::dbmanager
 * @param path
 */
dbmanager::dbmanager(const QString& path) {

    generate_sql_queries();

    // create/open the database
    u_db = QSqlDatabase::addDatabase("QSQLITE","u_db");
    u_db.setDatabaseName(path);

    if (!u_db.open()) {

        std::cerr << "Error: database connection failed"
                  << std::endl;
        exit(0);  // abort program
    } else {

        std::cout  << "Database: connection ok"
                   << std::endl;
    }

}

/**
 * @brief dbmanager::closeDB
 */
void dbmanager::closeDB(){
    QString connection = u_db.connectionName();
    u_db.close();
    u_db = QSqlDatabase();
    u_db.removeDatabase(connection);
}

/**
 * @brief dbmanager::generate_sql_queries
 */
void dbmanager::generate_sql_queries() {

    create_cmd += "create table userinfo ";
    create_cmd += "( id INT NOT NULL UNIQUE, username QSTRING NOT NULL UNIQUE, password QSTRING NOT NULL, type QSTRING NOT NULL, email QSTRING NOT NULL, phone INT NOT NULL);";

    insert_cmd += "INSERT INTO userinfo (id, username, password, type, email, phone) ";
    insert_cmd += "VALUES (:id, :username, :password, :type, :email, :phone);";

    drop_cmd   += "DROP TABLE IF EXISTS userinfo;";

    sql_query = nullptr;
}

/**
 * @brief dbmanager::build_table
 */
void dbmanager::build_table() {

    sql_query = new QSqlQuery(u_db);

    sql_query->exec(drop_cmd);   // drop existing table

    sql_query->exec(create_cmd); // create table

    delete sql_query;
}

/**
 * @brief dbmanager::create_row
 * @param username
 * @param password
 * @param type
 * @param email
 * @param phone
 * @return
 */
bool dbmanager::create_row(QString username, QString password, QString type, QString email, int phone) {

    sql_query = new QSqlQuery(u_db);

    sql_query->prepare(insert_cmd);

    sql_query->bindValue(":id",    id   );
    sql_query->bindValue(":username", username);
    sql_query->bindValue(":password", password);
    sql_query->bindValue(":type", type);
    sql_query->bindValue(":email", email);
    sql_query->bindValue(":phone", phone);

    if(sql_query->exec()){
        std::cout  << "success" << std::endl;
        id++;
        delete sql_query;
        return true;

    }
    else{
        delete sql_query;
        return false;
    }


    delete sql_query;
}

/**
 * @brief dbmanager::update_username
 * @param email
 * @param username
 */
void dbmanager::update_username(QString email, QString username) {
    QString update_cmd;

    update_cmd += "UPDATE userinfo ";
    update_cmd += "SET username = :username ";
    update_cmd += "WHERE email = :email;";

    sql_query = new QSqlQuery(u_db);

    sql_query->prepare(update_cmd);

    sql_query->bindValue(":email",    email);

    sql_query->bindValue(":username",    username);

    sql_query->exec();

    delete sql_query;
}

/**
 * @brief dbmanager::update_password
 * @param username
 * @param password
 */
void dbmanager::update_password(QString username, QString password) {
    QString update_cmd;

    update_cmd += "UPDATE userinfo ";
    update_cmd += "SET password = :password ";
    update_cmd += "WHERE username = :username;";

    sql_query = new QSqlQuery(u_db);

    sql_query->prepare(update_cmd);

    sql_query->bindValue(":username",    username);

    sql_query->bindValue(":password",    password);

    sql_query->exec();

    delete sql_query;
}

/**
 * @brief dbmanager::update_phone
 * @param username
 * @param phone
 */
void dbmanager::update_phone(QString username, int phone) {
    QString update_cmd;

    update_cmd += "UPDATE userinfo ";
    update_cmd += "SET phone = :phone ";
    update_cmd += "WHERE username = :username;";

    sql_query = new QSqlQuery(u_db);

    sql_query->prepare(update_cmd);

    sql_query->bindValue(":username",    username);

    sql_query->bindValue(":phone",    phone);

    sql_query->exec();

    delete sql_query;
}

/**
 * @brief dbmanager::update_email
 * @param username
 * @param email
 */
void dbmanager::update_email(QString username, QString email) {
    QString update_cmd;

    update_cmd += "UPDATE userinfo ";
    update_cmd += "SET email = :email ";
    update_cmd += "WHERE username = :username;";

    sql_query = new QSqlQuery(u_db);

    sql_query->prepare(update_cmd);

    sql_query->bindValue(":username",    username);

    sql_query->bindValue(":email",    email);

    sql_query->exec();

    delete sql_query;
}

/**
 * @brief dbmanager::loginAuthentication
 * @param uname
 * @param pword
 * @return
 */
bool dbmanager::loginAuthentication(QString uname, QString pword){
    QString find_cmd = "SELECT id, username, password FROM userinfo WHERE username = :username and password = :password;";
    sql_query = new QSqlQuery(u_db);
    sql_query->prepare(find_cmd);
    sql_query->bindValue(":username", uname);
    sql_query->bindValue(":password", pword);
    sql_query->exec();

    if(sql_query->next()){

        //int id = sql_query->value(0).toInt();
        QString username = sql_query->value(1).toString();
        QString password = sql_query->value(2).toString();

        return true;
    }
    else return false;
}

/**
 * @brief dbmanager::getType
 * @param uname
 * @param pword
 * @return
 */
QString dbmanager::getType(QString uname, QString pword){
    QString find_cmd = "SELECT id, username, password, type FROM userinfo WHERE username = :username and password = :password;";
    sql_query = new QSqlQuery(u_db);
    sql_query->prepare(find_cmd);
    sql_query->bindValue(":username", uname);
    sql_query->bindValue(":password", pword);
    sql_query->exec();

    if(sql_query->next()){

        QString utype = sql_query->value(3).toString();
        return utype;
    }
    else return NULL;
}


/**
 * @brief dbmanager::printDB
 */
void dbmanager::printDB(){
    //sql_query = new QSqlQuery(u_db);
    sql_query = new QSqlQuery("SELECT id, username, password, type, email, phone FROM userinfo");

    std::cout << "----------------start----------------------" << std::endl;
    while (sql_query->next()) {
        int id = sql_query->value(0).toInt();
        QString username = sql_query->value(1).toString();
        QString password = sql_query->value(2).toString();
        QString usertype = sql_query->value(3).toString();
        QString email = sql_query->value(4).toString();
        int phone = sql_query->value(5).toInt();


        std::cout << id
                  << "  "
                  << username.toStdString()
                  << "  "
                  << usertype.toStdString()
                  << "  "
                  << password.toStdString()
                  << "  "
                  << email.toStdString()
                  << "  "
                  << phone
                  << std::endl;
    }

    std::cout << "-----------------end---------------------" << std::endl;
   // delete sql_query;

}

