TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    adddic.cpp \
    color.cpp \
    error_open.cpp \
    window_size.cpp

HEADERS += \
    adddic.h \
    color.h \
    error_open.h \
    hash.h \
    logo.h \
    window_size.h
RC_FILE = dictionary.rc
TARGET = MyDictionary_v2_1
