#----------------------------------------------------------------------
# File:    qttestrunnerlib.pro
# Purpose: qmake config file for the QtTestRunner library.
#          The library is built in both debug and release configs as
#          shared library. Set the CONFIG variable accordingly to build
#          it differently.
#----------------------------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
TARGET = cppunit-qttestrunner
CONFIG += debug_and_release warn_on
CONFIG += dll # Set this to 'static' when building a static library

CPPUNIT_LIB = cppunit # cppunit library base name

CONFIG(debug, debug|release) {
    mac {
        TARGET = $$join(TARGET,,,_debug)
        CPPUNIT_LIB = $$join(CPPUNIT_LIB,,,_debug)
    }
    win32 {
        TARGET = $$join(TARGET,,,d)
        CPPUNIT_LIB = $$join(CPPUNIT_LIB,,,d)
    }
}

static { # everything below takes effect with CONFIG += static
    CONFIG += staticlib
    mac: TARGET = $$join(TARGET,,,_static)
    win32: TARGET = $$join(TARGET,,,s)
}

dll { # everything below takes effect with CONFIG += dll
    win32 {
        DEFINES += QTTESTRUNNER_DLL_BUILD
        TARGET = $$join(TARGET,,,_dll)
        CPPUNIT_LIB = $$join(CPPUNIT_LIB,,,_dll)
    }
}

# Link paths for the correct cppunit library
win32 {
    LIBS += $${CPPUNIT_LIB}.lib
}

unix {
    LIBS += -l$${CPPUNIT_LIB}
    target.path = /lib
    INSTALLS += target
}

INCLUDEPATH += ../../include

SOURCES += QtTestFailure.cpp \
    QtTestListener.cpp \
    QtTestRunner.cpp \
    TestBrowser.cpp \
    TestFailureTableModel.cpp \
    TestRunnerThread.cpp \
    TestRunnerWindow.cpp \
    TestRunnerWindowPrivate.cpp

HEADERS  += QtTestFailure.h \
    QtTestListener.h \
    TestBrowser.h \
    TestFailureTableModel.h \
    TestRunnerThread.h \
    TestRunnerWindow.h \
    TestRunnerWindowPrivate.h

FORMS    += TestBrowser.ui \
    TestRunnerWindow.ui
