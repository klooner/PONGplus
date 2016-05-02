TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pad.cpp \
    ball.cpp

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
    pad.h \
    ball.h
