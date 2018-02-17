TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    adddic.cpp \
    color.cpp \
    error_open.cpp \
    treeoption.cpp \
    search.cpp

DISTFILES += \
    time

HEADERS += \
    about.h \
    adddic.h \
    color.h \
    error_open.h \
    hash.h \
    logo.h \
    time_chrono.h \
    treeoption.h
RC_FILE = dictionary.rc
