#-------------------------------------------------
#
# Project created by QtCreator 2018-11-01T01:03:14
#
#-------------------------------------------------

QT +=    core gui multimedia multimediawidgets


QT +=    sql
QT += qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetdesktop2A
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    access.cpp \
    fenetre.cpp \
    connection.cpp \
    point_dacces.cpp \
    cam.cpp \
    camera.cpp \
    live.cpp \
    notification.cpp

HEADERS += \
        mainwindow.h \
    access.h \
    fenetre.h \
    connection.h \
    point_dacces.h \
    cam.h \
    camera.h \
    live.h \
    notification.h

FORMS += \
        mainwindow.ui \
    access.ui \
    fenetre.ui \
    cam.ui \
    live.ui

QMAKE_CXXFLAGS += -std=gnu++14
