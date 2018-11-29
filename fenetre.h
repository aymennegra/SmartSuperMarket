#ifndef FENETRE_H
#define FENETRE_H

#include <QDialog>
#include"point_dacces.h"
#include <QMediaPlayer>


namespace Ui {
class Fenetre;
}

class Fenetre : public QDialog
{
    Q_OBJECT

public:
    explicit Fenetre(QWidget *parent = nullptr);
    ~Fenetre();

private slots:

    void on_pushButton_clicked();


   void on_suppref_clicked();
 void on_tableView_activated(const QModelIndex &index);


 void on_pushButton_2_clicked();

 void on_pushButton_3_clicked();

 void on_pushButton_4_clicked();

 void on_rechercherref_clicked();

private:
    Ui::Fenetre *ui;
    point_dacces tmppoint_dacces;
    point_dacces p;
    QMediaPlayer* player;


};

#endif // FENETRE_H
