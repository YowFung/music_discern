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
    app.cpp \
    lib/camera/discern.cpp \
    lib/midifile/instrument.cpp \
    lib/midifile/midifile.cpp \
    lib/midifile/midinote.cpp \
    lib/midifile/miditrack.cpp \
    lib/player/player.cpp \
    lib/player/playlist.cpp


HEADERS  += \
    app.h \
    lib/camera/discern.h \
    lib/midifile/instrument.h \
    lib/midifile/midifile.h \
    lib/midifile/midinote.h \
    lib/midifile/miditrack.h \
    lib/player/player.h \
    lib/player/playlist.h


FORMS    += \
    app.ui

RC_ICONS = resource/app/favicon.ico

DISTFILES += \
    config/instruments.json \
    config/playlist.json \
    config/instruments.txt

RESOURCES += \
    resource.qrc
