TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

QT += core                # this should be added
QT += sql                 # this should be added

LIBS    += -lncurses

SOURCES += main.cpp \
    dbmanager.cpp \
    msgdb.cpp \
    contactlistdb.cpp \
    reportdb.cpp

HEADERS += \
    dbmanager.h \
    msgdb.h \
    contactlistdb.h \
    reportdb.h
