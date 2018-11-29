#include "cam.h"
#include "ui_cam.h"
#include "access.h"
#include <QDebug>
#include "connection.h"
#include "live.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMediaPlayer>
#include "notification.h"
#include <QtWidgets>
#include <QPixmap>

cam::cam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cam)
{
    ui->setupUi(this);
    ui->tabcam->setModel(tmpcam.afficher());
    player = new QMediaPlayer (this);
    ui->camannim->setMask((new QPixmap("annim.gif"))->mask());
        QMovie *movie=new QMovie("annim.gif");
        ui->camannim->setMovie(movie);
        movie->start();

}

cam::~cam()
{
    delete ui;
}



/************ajouter fenetre********/

void cam::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
    notification n;

    int refcam = ui->referencecam->text().toInt();
    QString empcam= ui->emplacementcam->text();
  camera c(refcam,empcam);
  ui->referencecam->clear();
  ui->emplacementcam->clear();

  bool test=c.ajouter();
  n.notification_ajout(refcam);

  if(test)
  {ui->tabcam->setModel(tmpcam.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un camera "),
                  QObject::tr(" ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un camera"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


/************supprimer fenetre********/
void cam::on_pushButton_3_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
    int refcam = ui->suppref->text().toInt();
    ui->suppref->clear();
        bool test=tmpcam.supprimer(refcam);
        if(test)
       {ui->tabcam->setModel(tmpcam.afficher());//refresh
            QMessageBox::information(nullptr, QObject::tr("Supprimer un camera"),
                        QObject::tr("camera supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un camera"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

/************modifier fenetre********/
void cam::on_pushButton_2_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
    int refcam= ui->modifref->text().toInt();
    QString empcam= ui->modifemp->text();
    camera c(refcam,empcam);
    ui->modifref->clear();
    ui->modifemp->clear();

    ui->emplacementcam->clear();
    bool test=c.modifier();
    if (test)
    {ui->tabcam->setModel(tmpcam.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un camera"),
                    QObject::tr("camera modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un camera"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void cam::on_pushButton_4_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
    access afficher;
    afficher.setModal(true);
     this->hide();
    afficher.exec();
}




void cam::on_livecam_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
    live afficher;
    afficher.setModal(true);
     //this->hide();
    afficher.exec();
}




void cam::on_pushButton_5_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
    QString refcam=ui->refrech->text();
        ui->refrech->clear();
        QSqlQueryModel *model;
        camera *a=new camera();

              QString empcam;
              QString etat ;
              QString type ;
              QString emplacement;
                QSqlQuery  *q  = new QSqlQuery();
                q->prepare("SELECT* FROM CAMERA WHERE REFCAM=?");
                q->addBindValue(refcam);
                if(q->exec())
                {
                    while(q->next())
                    {

                        refcam=q->value(0).toString();
                         empcam=q->value(1).toString();

                    }
                }

                ui->modifref->setText(refcam);
                ui->modifemp->setText(empcam);
     ;
}

