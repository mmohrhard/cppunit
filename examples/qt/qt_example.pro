#----------------------------------------------------------------------
# File:    qt_example.pro
# Purpose: qmake config file for the QtTestRunner example.
#          The program is built with the QtTestRunner shared library in
#          both debug and release configs.
#          Set the CONFIG variable accordingly to build it differently.
#----------------------------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_example
TEMPLATE = app

CONFIG += use_dll
#CONFIG += use_static

CONFIG += warn_on

#----------------------------------------------------------------------
# MS Windows
#----------------------------------------------------------------------

win32 {
    use_dll {
        DEFINES += QTTESTRUNNER_DLL
        debug {
            LIBS += cppunitd_dll.lib
            LIBS += cppunit-qttestrunnerd_dll.lib
        }
        release {
            LIBS += cppunit_dll.lib
            LIBS += cppunit-qttestrunner_dll.lib
        }
    }
    use_static {
        debug {
            LIBS += cppunitd.lib
            LIBS += cppunit-qttestrunnerd.lib
        }
        release {
            LIBS += cppunit.lib
            LIBS += cppunit-qttestrunner.lib
        }
    }
}

#----------------------------------------------------------------------
# Linux/Unix
#----------------------------------------------------------------------

unix {
    LIBS += -lcppunit-qttestrunner
    LIBS += -lcppunit
}

#----------------------------------------------------------------------

HEADERS = \
        ExampleTestCases.h

SOURCES = \
        ExampleTestCases.cpp \
        Main.cpp

INCLUDEPATH += . ../../include
