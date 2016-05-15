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
    utils.cpp \
    visualtab.cpp \
    switch.cpp \
    task_objectiveflyaround.cpp \
    task_platformhopperleft.cpp \
    task_platformhopperright.cpp

HEADERS  += mainwindow.h \
    audiotab.h \
    tasktab.h \
    task_passiveflyaround.h \
    utils.h \
    visualtab.h \
    switch.h \
    task_objectiveflyaround.h \
    task_platformhopperleft.h \
    task_platformhopperright.h

FORMS    += mainwindow.ui \
    audiotab.ui \
    tasktab.ui \
    task_passiveflyaround.ui \
    visualtab.ui \
    switch.ui \
    task_objectiveflyaround.ui \
    task_platformhopperleft.ui \
    task_platformhopperright.ui

RESOURCES += \
    resources.qrc

DISTFILES +=
