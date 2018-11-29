#include "porte.h"
#include "ui_porte.h"


Porte::Porte(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Porte)
{
    ui->setupUi(this);
}

Porte::~Porte()
{
    delete ui;
}

