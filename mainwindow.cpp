#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "access.h"
#include "connection.h"
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QtDebug>
#include "fenetre.h"
#include "cam.h"
#include <QMediaPlayer>
#include <QSound>
#include <QtWidgets>
#include <QPixmap>
//#include "livecam.h"



//#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    annimation = new QPropertyAnimation (ui->agent,"geometry");
    annimation->setDuration(10000);
    annimation->setStartValue(ui->agent->geometry());
    annimation->setEndValue(QRect(1000,500,100,100));
    annimation->start();
    player = new QMediaPlayer (this);
    connect (player ,&QMediaPlayer::positionChanged, this,&MainWindow::on_positionChanged);
    connect (player ,&QMediaPlayer::durationChanged, this,&MainWindow::on_durationChanged);
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/Downloads/Music/Tonyz.mp3"));
    player->play();
    qDebug()<<player->errorString();
    ui->label->setMask((new QPixmap("annim.gif"))->mask());
        QMovie *movie=new QMovie("annim.gif");
        ui->welcome->setMovie(movie);
        movie->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/projetdesktop2A/ComputerMouse.aif"));
    player->play();
    qDebug()<<player->errorString();
   if((ui->login->text()=="aymen") && (ui->login2->text()=="0000"))
            {
            access afficher;
            afficher.setModal(true);
             //this->hide();
            afficher.exec();
            }
else
            QMessageBox::critical(nullptr, QObject::tr("incorrect password"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_slideprogress_sliderMoved(int position)
{
    player->setPosition(position);
}

void MainWindow::on_slidevolume_sliderMoved(int position)
{
    player->setVolume(position);
}


void MainWindow::on_pushButton_4_clicked()
{
    i++;
        if (i % 2==0){
            player->stop();
        }else{
            player->setMedia(QUrl::fromLocalFile("C:/Users/Negra Aymen/Downloads/Music/Tonyz.mp3"));
            player->play();
            qDebug()<<player->errorString();
        }
}

void MainWindow::on_positionChanged(quint64 position)
{
    ui->slideprogress->setValue(position);
}

void MainWindow::on_durationChanged(quint64 position)
{
    ui->slideprogress->setMaximum(position);
}





