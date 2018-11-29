#include "live.h"
#include "ui_live.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>





live::live(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::live)
{
    ui->setupUi(this);
    mCamera =new QCamera(this);
    mCameraViewfinder =new QCameraViewfinder(this);
    mCameraImageCapture =new QCameraImageCapture(mCamera,this);
    mLayout=new QVBoxLayout;
    optionmenu=new QMenu("option",this);
    closeAction = new QAction ("close",this);
    openAction = new QAction ("open",this);
    capturAction = new QAction ("captur",this);

    optionmenu->addActions({closeAction,openAction,capturAction});
    ui->optioncam->setMenu(optionmenu);
    mCamera->setViewfinder(mCameraViewfinder);

    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);

    connect(closeAction ,&QAction::triggered, [&](){
        mCamera->stop();
    });
    connect(openAction ,&QAction::triggered, [&](){
        mCamera->start();
    });
    connect(capturAction ,&QAction::triggered, [&](){
        auto filename=QFileDialog::getSaveFileName(this, "captur", "/",
                                                   "image (*.jpg;*.jpeg)");
        if (filename.isEmpty())
        {
            return;
        }
        mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
        QImageEncoderSettings imageEncoderSettings;
        imageEncoderSettings.setCodec("image/jpeg");
        imageEncoderSettings.setResolution(1600, 1200);
        mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
        mCamera->setCaptureMode(QCamera::CaptureStillImage);
        mCamera->start();
        mCamera->searchAndLock();
        mCameraImageCapture->capture(filename);
        mCamera->unlock();
    });


}


live::~live()
{
    delete ui;
}
