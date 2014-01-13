QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = phystat
TEMPLATE = app
CONFIG += precompile_header

PRECOMPILED_HEADER = precom.h

HEADERS += \
    style.h \
    phystat.h \
    main.h \
    metenglayout.h \
    wlineedit.h \
    precom.h

SOURCES += \
    style.cpp \
    phystat.cpp \
    main.cpp \
    metenglayout.cpp \
    wlineedit.cpp
