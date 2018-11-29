#ifndef CAM_H
#define CAM_H

#include <QDialog>
#include "camera.h"
#include <QMediaPlayer>

namespace Ui {
class cam;
}



class cam : public QDialog
{
    Q_OBJECT

public:
    explicit cam(QWidget *parent = nullptr);
    ~cam();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_optioncam_clicked();

    void on_pushButton_5_clicked();

    void on_livecam_clicked();

    void on_nomrech_clicked();

    void on_rechercher_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::cam *ui;
    camera tmpcam;
    camera c;
    QMediaPlayer* player;


};

#endif // CAM_H
