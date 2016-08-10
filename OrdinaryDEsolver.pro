TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    System.cpp \
    State.cpp \
    Solver.cpp \
    EulerSolver.cpp \
    RungeKuttaSolver.cpp \
    GodunovSolver.cpp \
    Writer.cpp \
    GalerkinSolver.cpp

HEADERS += \
    System.h \
    State.h \
    Solver.h \
    EulerSolver.h \
    RungeKuttaSolver.h \
    GodunovSolver.h \
    Writer.h \
    GalerkinSolver.h

