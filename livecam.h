#ifndef LIVECAM_H
#define LIVECAM_H

#include <QWidget>

namespace Ui {
class livecam;
}



class livecam : public QWidget
{
    Q_OBJECT

public:
    explicit livecam(QWidget *parent = nullptr);
    ~livecam();

private:
    Ui::livecam *ui;


#endif // LIVECAM_H
