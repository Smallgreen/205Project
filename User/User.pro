TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    userbase.cpp \
    citizen.cpp \
    firstresponder.cpp \
    emergencyplanner.cpp

HEADERS += \
    userbase.h \
    citizen.h \
    firstresponder.h \
    emergencyplanner.h
