#ifndef CAMERALIVE_H
#define CAMERALIVE_H

#include <QWidget>

namespace Ui {
class cameralive;
}

class cameralive : public QWidget
{
    Q_OBJECT

public:
    explicit cameralive(QWidget *parent = nullptr);
    ~cameralive();

private:
    Ui::cameralive *ui;
};

#endif // CAMERALIVE_H
