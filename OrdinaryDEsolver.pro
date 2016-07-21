TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    System.cpp \
    State.cpp \
    Solver.cpp

HEADERS += \
    System.h \
    State.h \
    Solver.h

