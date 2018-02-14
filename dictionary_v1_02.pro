TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    adddic.cpp \
    window_size.cpp \
    error_open.cpp \
    color.cpp

HEADERS += \
    adddic.h \
    window_size.h \
    error_open.h \
    color.h \
    hash.h \
    logo.h \
    time_chrono.h \
    about.h
RC_FILE = dictionary.rc
TARGET = MyDictionary_v2_1
