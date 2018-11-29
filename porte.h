#ifndef PORTE_H
#define PORTE_H

#include <QDialog>

namespace Ui {
class Porte;
}

class Porte : public QDialog
{
    Q_OBJECT

public:
    explicit Porte(QWidget *parent = nullptr);
    ~Porte();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Porte *ui;
};

#endif // PORTE_H
