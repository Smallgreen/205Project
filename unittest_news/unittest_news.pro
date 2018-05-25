TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += ../News/newsfeed.h \
           ../News/newsitem.h   \
           ../News/report.h

SOURCES += main.cpp     \
           ../News/newsfeed.cpp     \
           ../News/newsitem.cpp     \
           ../News/report.cpp

