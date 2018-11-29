#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QtDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

    void on_slideprogress_sliderMoved(int position);

    void on_slidevolume_sliderMoved(int position);

    void on_pushButton_4_clicked();

    void on_positionChanged(quint64 position);
    void on_durationChanged(quint64 position);

    void on_pushButton_2_clicked();

    void on_livecam_clicked();

private:
    Ui::MainWindow *ui;
    QPropertyAnimation *annimation;
    QMediaPlayer* player;
    int i=1;


};

#endif // MAINWINDOW_H
