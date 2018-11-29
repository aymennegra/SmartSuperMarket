#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>


class connection
{
private:
    QSqlDatabase db;
public:
    connection();
    bool ouvrirconnection();
    void fermerconnection();

};

#endif // CONNECTION_H
