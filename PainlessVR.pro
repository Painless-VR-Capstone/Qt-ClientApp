#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T10:22:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PainlessVR
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    audiotab.cpp \
    tasktab.cpp \
    task_passiveflyaround.cpp \
    task_platformhopper.cpp \
    utils.cpp \
    visualtab.cpp

HEADERS  += mainwindow.h \
    audiotab.h \
    tasktab.h \
    task_passiveflyaround.h \
    task_platformhopper.h \
    utils.h \
    visualtab.h

FORMS    += mainwindow.ui \
    audiotab.ui \
    tasktab.ui \
    task_passiveflyaround.ui \
    task_platformhopper.ui \
    visualtab.ui

RESOURCES += \
    resources.qrc

DISTFILES +=
