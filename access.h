#ifndef ACCESS_H
#define ACCESS_H

#include <QDialog>
#include <QMediaPlayer>

namespace Ui {
class access;
}

class access : public QDialog
{
    Q_OBJECT

public:
    explicit access(QWidget *parent = nullptr);
    ~access();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_cam_clicked();

private:
    Ui::access *ui;
    QMediaPlayer* player;
};

#endif // ACCESS_H
