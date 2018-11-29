#include "fenetre.h"
#include "ui_fenetre.h"
#include "access.h"
#include <QDebug>
#include "point_dacces.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMediaPlayer>
#include "notification.h"
#include <QtWidgets>
#include <QPixmap>


Fenetre::Fenetre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fenetre)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmppoint_dacces.afficher());
    player = new QMediaPlayer (this);
    ui->ptannim->setMask((new QPixmap("annim.gif"))->mask());
        QMovie *movie=new QMovie("annim.gif");
        ui->ptannim->setMovie(movie);
        movie->start();
}

Fenetre::~Fenetre()
{
    delete ui;
}

/************ajouter fenetre********/


void Fenetre::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
    notification n;
    int ref = ui->ref->text().toInt();
    QString nom= ui->nom->text();
    QString type = ui->type->text();
    QString emplacement= ui->emplacement->text();
    int etat = ui->etat->text().toInt();
  point_dacces p(ref,nom,type,emplacement,etat);
  ui->ref->clear();
  ui->nom->clear();
  ui->emplacement->clear();
  ui->type->clear();
  ui->etat->clear();
  bool test=p.ajouter();
  n.notification_ajout(ref);
  if(test)
  {ui->tableView->setModel(tmppoint_dacces.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un point_dacces "),
                  QObject::tr("point_dacces ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un point_dacces"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

/************supprimer fenetre********/

void Fenetre::on_suppref_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();

    int ref = ui->reff->text().toInt();
      ui->reff->clear();
        bool test=tmppoint_dacces.supprimer(ref);
        if(test)
       {ui->tableView->setModel(tmppoint_dacces.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un point d'acces"),
                        QObject::tr("point d'acces supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un point d'acces"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

/************modifier fenetre********/
void Fenetre::on_pushButton_2_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
    int ref= ui->modifref->text().toInt();
    QString nom= ui->modifnom->text();
    QString type= ui->modiftype->text();
    QString emplacement= ui->modifemp->text();
    int etat= ui->modifetat->text().toInt();
    point_dacces p(ref,nom,type,emplacement,etat);
    ui->modifref->clear();
    ui->modifnom->clear();
    ui->modifemp->clear();
    ui->modiftype->clear();
    ui->modifetat->clear();
    bool test=p.modifier();
    if (test)
    {ui->tableView->setModel(tmppoint_dacces.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un point d'acces"),
                    QObject::tr("point d'acces modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un point d'acces"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }



/******************rechercher*****************/

void Fenetre::on_pushButton_4_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
    access afficher;
    afficher.setModal(true);
     this->hide();
    afficher.exec();
}

void Fenetre::on_rechercherref_clicked()
{
    QString ref=ui->nomrech_2->text();
        ui->nomrech_2->clear();
        QSqlQueryModel *model;
        point_dacces *a=new point_dacces();

              QString nom;
              QString etat ;
              QString type ;
              QString emplacement;

                QSqlQuery  *q  = new QSqlQuery();
                q->prepare("SELECT* FROM POINT_DACCES WHERE REF=?");
                q->addBindValue(ref);
                if(q->exec())
                {
                    while(q->next())
                    {

                        ref=q->value(0).toString();
                         nom=q->value(1).toString();
                        type=q->value(2).toString();
                       emplacement=q->value(3).toString();
                       etat=q->value(4).toString();

                    }
                }

                ui->modifref->setText(ref);
                ui->modifnom->setText(nom);
                ui->modiftype->setText(type);
                ui->modifemp->setText(emplacement);
                ui->modifetat->setText(etat);

    }


