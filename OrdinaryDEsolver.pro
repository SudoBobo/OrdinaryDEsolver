message(Qt version: $$[QT_VERSION])
message($$QMAKESPEC)

linux-g++ {
    message(Linux)
}
TEMPLATE = app
CONFIG += console c++11
QMAKE_CXXFLAGS += -O3
CONFIG -= app_bundle
CONFIG -= qt
CONFIG(debug, debug|release) {
    CONFIG -= -O3
    CONFIG += -O0
}

SOURCES += main.cpp \
    System.cpp \
    State.cpp \
    Solver.cpp \
    Writer.cpp \
    GalerkinSolver.cpp \
    Method.cpp \
    RungeKuttaMethod.cpp \
    Stream.cpp \
    GodunovStream.cpp \
    MyMath.cpp \
    Polynomial.cpp \
    Limiter.cpp \
    MUSCLLimiter.cpp \
    Conditions.cpp

HEADERS += \
    System.h \
    State.h \
    Solver.h \
    Writer.h \
    GalerkinSolver.h \
    Method.h \
    RungeKuttaMethod.h \
    Stream.h \
    GodunovStream.h \
    MyMath.h \
    Polynomial.h \
    Limiter.h \
    MUSCLLimiter.h \
    Conditions.h
