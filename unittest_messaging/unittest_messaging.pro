TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH +=  ../googletest-master                                   \
                ../googletest-master/googletest                        \
                ../googletest-master/googletest/include                \
                ../googletest-master/googletest/include/gtest

HEADERS += ../Messaging/contactlist.h \
           ../Messaging/messagelist.h

SOURCES += main.cpp \
           ../Messaging/contactlist.cpp

