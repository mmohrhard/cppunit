#include <QApplication>

#include <cppunit/TestSuite.h>
#include <cppunit/ui/qt/QtTestRunner.h>

#include "TestRunnerWindow.h"

CPPUNIT_NS_BEGIN

//
// QtTestRunnerPrivate
//

// Define a few types for better readability (and usability) later on
typedef Test* TestPtr;
typedef QVector< TestPtr > TestPtrList;
typedef QVectorIterator< TestPtr > TestPtrListIterator;

class QtTestRunnerPrivate
{
    typedef QScopedPointer< TestSuite > TestSuitePtr;

public:
    QtTestRunnerPrivate()
        : _suite(new TestSuite("All Tests"))
        , _tests()
        , _dialog()
    {}

    ~QtTestRunnerPrivate()
    {}

    Test *rootTest()
    {
        if (_tests.size() != 1)
        {
            TestPtrListIterator it(_tests);
            while (it.hasNext())
            {
                _suite->addTest(it.next());
            }

            _tests.clear();
            return _suite.data();
        }

        return _tests.at(0);
    }

public:
    TestSuitePtr _suite;
    TestPtrList _tests;
    QScopedPointer<TestRunnerWindow> _dialog;
};

//
// QtTestRunner
//

QtTestRunner::QtTestRunner()
    : _d(new QtTestRunnerPrivate)
{}

QtTestRunner::~QtTestRunner()
{
    TestPtrListIterator it(_d->_tests);
    while (it.hasNext())
        delete it.next();
}

void QtTestRunner::run(bool autorun)
{
    _d->_dialog.reset(new TestRunnerWindow(_d->rootTest()));

    if (autorun)
        _d->_dialog->startTesting();

    _d->_dialog->show();
}

void QtTestRunner::addTest(Test *test)
{
    _d->_tests.append(test);
}

CPPUNIT_NS_END
