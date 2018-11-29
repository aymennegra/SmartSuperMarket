#include "point_dacces.h"
#include "connection.h"
#include <QDebug>



point_dacces::point_dacces()
{

    ref=0;
    nom="";
    type="";
    emplacement="";
    etat=0;
    }
    point_dacces::point_dacces(int ref,QString nom,QString type,QString emplacement,int etat)
    {
      this->ref=ref;
      this->nom=nom;
      this->type=type;
      this->emplacement=emplacement;
      this->etat=etat;
    }
    int point_dacces::get_ref(){return  ref;}
    QString point_dacces::get_nom(){return  nom;}
    QString point_dacces::get_type(){return  type;}
    QString point_dacces::get_emplacement(){return emplacement;}
    int point_dacces::get_etat(){return  etat;}
    /********************ajout*************************/
    bool point_dacces::ajouter()
    {
    QSqlQuery query;
    query.prepare("INSERT INTO POINT_DACCES (REF, NOM , TYPE , EMPLACEMENT , ETAT ) VALUES (:ref, :nom, :type, :emplacement, :etat)");
    query.bindValue(":ref", ref);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":emplacement", emplacement);
    query.bindValue(":etat", etat);

    return    query.exec();
    }
    /********************afficher*********************/
    QSqlQueryModel * point_dacces::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from POINT_DACCES ORDER BY REF");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMPLACEMENT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));
        return model;
    }
    /*********************supprimer*******************/

    bool point_dacces::supprimer(int ref){
        QSqlQuery query;
        query.prepare("Delete from POINT_DACCES where ref = :ref ");
        query.bindValue(":ref", ref);
        return    query.exec();
    }

 /*********************modifier*******************/
    bool point_dacces::modifier()
    {
        QSqlQuery query;
        query.prepare("UPDATE POINT_DACCES set nom=:nom,type=:type,emplacement=:emplacement,etat=:etat where (ref=:ref)");
        query.bindValue(":ref", ref);
        query.bindValue(":nom", nom);
        query.bindValue(":type", type);
        query.bindValue(":emplacement", emplacement);
        query.bindValue(":etat", etat);
return query.exec();

    }

