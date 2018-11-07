#-------------------------------------------------
#
# Project created by QtCreator 2018-11-06T23:16:06
#
#-------------------------------------------------

QT      += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BURT_UX
TEMPLATE = app


SOURCES += main.cpp\
        burtwindow.cpp \
    src/JsonParser.cpp \
    src/VoiceToText.cpp

HEADERS  += burtwindow.h \
    src/JsonParser.h \
    src/VoiceToText.h

FORMS    += burtwindow.ui

unix: CONFIG += link_pkgconfig
unix|win32: LIBS += -lcurl

unix|win32: LIBS += -ljsoncpp
