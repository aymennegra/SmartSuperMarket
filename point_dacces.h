#ifndef POINT_DACCES_H
#define POINT_DACCES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class point_dacces
{
public:
    point_dacces();
    point_dacces(int,QString,QString,QString,int);
    int get_ref();
    QString get_nom();
    QString get_type();
    QString get_emplacement();
    int get_etat();
    bool ajouter();
    QSqlQueryModel * afficher ();
    QSqlQueryModel *rechercher(int ref);



    bool supprimer(int);
    bool modifier();
private:
    QString nom,emplacement,type;
    int ref,etat;
};

#endif // POINT_DACCES_H
