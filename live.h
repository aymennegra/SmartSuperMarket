#ifndef LIVE_H
#define LIVE_H

#include <QDialog>


namespace Ui {
class live;
}
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;
class live : public QDialog
{
    Q_OBJECT

public:
    explicit live(QWidget *parent = nullptr);
    ~live();

private:
    Ui::live *ui;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *optionmenu;
    QAction *closeAction;
    QAction *openAction;
    QAction *capturAction;

};

#endif // LIVE_H
