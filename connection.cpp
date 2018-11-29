#include "connection.h"



connection::connection()
{}
bool connection::ouvrirconnection()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projetdesktop2A");
    db.setUserName("aymen");
    db.setPassword("esprit18");
    if(db.open())

        test=true;
        return test;

}
void connection::fermerconnection()
{db.close();}
