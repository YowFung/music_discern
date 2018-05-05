#-------------------------------------------------
#
# Project created by QtCreator 2018-05-05T22:30:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = music_discern
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    music_discern.cpp

HEADERS  += \
    music_discern.h

FORMS    += \
    music_discern.ui

RC_ICONS = images/favicon.ico

DISTFILES += \
    images/scores/爱尔兰画眉.jpg \
    images/components/Widgets/scroll_down.png \
    images/components/Widgets/scroll_up.png \
    images/components/btn_delete.png \
    images/components/btn_edit.png \
    images/components/item_info.png \
    images/components/last.png \
    images/components/music.png \
    images/components/nav-discern.png \
    images/components/nav-exit.png \
    images/components/nav-list.png \
    images/components/nav-menu.png \
    images/components/nav-play.png \
    images/components/next.png \
    images/components/pause.png \
    images/components/play.png \
    images/components/stop.png \
    images/example/disc_camera_exam.png \
    images/favicon.png \
    images/favicon.ico
