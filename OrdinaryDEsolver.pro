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
    streams/Stream.cpp \
    limiters/LimiterN2.cpp \
    limiters/LimiterN3.cpp \
    limiters/LimiterN2BM.cpp \
    limiters/LimiterN3BM.cpp \
    limiters/MUSCLLimiterBM.cpp \
    limiters/Limiter.cpp \
    limiters/MUSCLLimiter.cpp \
    streams/GodunovStream.cpp \
    streams/Stream.cpp \
    support/Conditions.cpp \
    support/FileWriter.cpp \
    support/MyMath.cpp \
    support/Problem.cpp \
    support/Solver.cpp \
    support/State.cpp \
    systemMakers/GalerkinSystemMaker.cpp \
    systemMakers/SystemMaker.cpp \
    systemSolvers/EulerSystemSolver.cpp \
    systemSolvers/RungeKuttaSystemSolver.cpp \
    systemSolvers/SystemSolver.cpp

HEADERS += \
    limiters/Limiter.h \
    limiters/LimiterN2.h \
    limiters/LimiterN2BM.h \
    limiters/LimiterN3.h \
    limiters/LimiterN3BM.h \
    limiters/MUSCLLimiter.h \
    limiters/MUSCLLimiterBM.h \
    streams/GodunovStream.h \
    streams/Stream.h \
    support/Conditions.h \
    support/FileWriter.h \
    support/MyMath.h \
    support/Problem.h \
    support/Solver.h \
    support/State.h \
    systemMakers/GalerkinSystemMaker.h \
    systemMakers/SystemMaker.h \
    systemSolvers/EulerSystemSolver.h \
    systemSolvers/RungeKuttaSystemSolver.h \
    systemSolvers/SystemSolver.h

    EulerSystemSolver.h \
    limiters/LimiterN2.h \
    limiters/LimiterN3.h \
    limiters/LimiterN2BM.h \
    limiters/LimiterN3BM.h \
    limiters/MUSCLLimiterBM.h \
    limiters/Limiter.h \
    limiters/MUSCLLimiter.h \
    streams/GodunovStream.h \
    streams/Stream.h \
    support/Conditions.h \
    support/FileWriter.h \
    support/MyMath.h \
    support/Problem.h \
    support/Solver.h \
    support/State.h \
    systemMakers/GalerkinSystemMaker.h \
    systemMakers/SystemMaker.h \
    systemSolvers/EulerSystemSolver.h \
    systemSolvers/RungeKuttaSystemSolver.h \
    systemSolvers/SystemSolver.h

DISTFILES +=
