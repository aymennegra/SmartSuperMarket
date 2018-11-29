#include "cameralive.h"
#include "ui_cameralive.h"

cameralive::cameralive(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cameralive)
{
    ui->setupUi(this);

}

cameralive::~cameralive()
{
    delete ui;
}
