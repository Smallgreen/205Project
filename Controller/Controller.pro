TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

QT += core                # this should be added
QT += sql                 # this should be added

QT       += core gui webengine webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UI
LIBS    += -lncurses

SOURCES += main.cpp \
    ../database/dbmanager.cpp \
    ../database/contactlistdb.cpp \
    ../database/msgdb.cpp \
    ../database/reportdb.cpp \
    ../UI/mainwindow.cpp \
    ../UI/logindlg.cpp \
    ../UI/registerdlg.cpp \
    ../UI/main_fr.cpp \
    ../UI/main_ep.cpp \
    ../UI/messagewindow.cpp \
    ../UI/messagedlg.cpp \
    ../UI/main_ctz.cpp \
    ../UI/reportdlg.cpp \
    ../UI/newswindow.cpp \
    ../UI/alertwindow.cpp \
    ../UI/verifywindow.cpp \
    ../UI/simwindow.cpp


HEADERS += \
    ../database/dbmanager.h \
    ../database/contactlistdb.h \
    ../database/msgdb.h \
    ../database/reportdb.h \
    ../UI/mainwindow.h \
    ../UI/logindlg.h \
    ../UI/registerdlg.h \
    ../UI/main_fr.h \
    ../UI/main_ep.h \
    ../UI/main_ctz.h \
    ../UI/messagewindow.h \
    ../UI/messagedlg.h \
    ../UI/reportdlg.h \
    ../UI/newswindow.h \
    ../UI/alertwindow.h \
    ../UI/verifywindow.h \
    ../UI/simwindow.h

FORMS += \
    ../UI/mainwindow.ui \
    ../UI/logindlg.ui \
    ../UI/registerdlg.ui \
    ../UI/main_fr.ui \
    ../UI/messagewindow.ui \
    ../UI/messagedlg.ui \
    ../UI/main_ep.ui \
    ../UI/main_ctz.ui \
    ../UI/reportdlg.ui \
    ../UI/newswindow.ui \
    ../UI/alertwindow.ui \
    ../UI/verifywindow.ui \
    ../UI/simwindow.ui

