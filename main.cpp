#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QtDebug>
#include <QGuiApplication>
#include <QQuickView>
#include <QQmlEngine>
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;
    a.setStyle("fusion");
    bool test=c.ouvrirconnection();
    if (test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection succeeded.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}

