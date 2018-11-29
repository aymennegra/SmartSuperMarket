#include "access.h"
#include "ui_access.h"
#include "fenetre.h"
#include "cam.h"
#include <QMediaPlayer>
#include "mainwindow.h"
#include <QDebug>
#include <QtWidgets>
#include <QPixmap>
access::access(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::access)
{
    ui->setupUi(this);
    player = new QMediaPlayer (this);
    ui->accesannim->setMask((new QPixmap("annim.gif"))->mask());
        QMovie *movie=new QMovie("annim.gif");
        ui->accesannim->setMovie(movie);
        movie->start();
}

access::~access()
{
    delete ui;
}


void access::on_pushButton_2_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
    Fenetre afficher;
    afficher.setModal(true);
    this->hide();
    afficher.exec();
}






void access::on_cam_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
    cam afficher;
    afficher.setModal(true);
    this->hide();
    afficher.exec();
}
