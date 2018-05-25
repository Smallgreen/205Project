TEMPLATE = subdirs
CONFIG += console c11
CONFIG -= app_bundle
CONFIG -= qt
QT += location
QT += webenginewidgets


SOURCES += main.cpp \


HEADERS += \

SUBDIRS += \
    database \
    unittest \
    UI \
    Controller
