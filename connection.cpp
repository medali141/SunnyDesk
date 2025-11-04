#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("TNS Service Name");
    db.setUserName("rayensql");//inserer nom de l'utilisateur
    db.setPassword("esprit25");//inserer mot de passe de cet utilisateur
    if (db.open())
        test=true;
    return  test;
}

void Connection::closeConnection()
{
    db.close();
}
