#include <QMutex>
#include <QMutexLocker>

#include "TestRunnerThread.h"

//
// TestRunnerThreadPrivate
//

class TestRunnerThreadPrivate
{
    typedef CPPUNIT_NS::Test Test;
    typedef CPPUNIT_NS::TestResult TestResult;

public:
    TestRunnerThreadPrivate()
        : _test(NULL)
        , _result(NULL)
        , _mutex()
    {}

public:
    Test *_test;
    TestResult *_result;
    QMutex _mutex;
};

//
// TestRunnerThread
//

TestRunnerThread::TestRunnerThread(QObject *parent)
    : QThread(parent)
    , _d(new TestRunnerThreadPrivate)
{}

TestRunnerThread::~TestRunnerThread()
{}

void TestRunnerThread::adviseToStop()
{
    if (_d->_result)
        _d->_result->stop();
}

void TestRunnerThread::setTestInformation(Test *testToRun, TestResult *result)
{
    QMutexLocker lock(&_d->_mutex);
    _d->_test = testToRun;
    _d->_result = result;
}

void TestRunnerThread::run()
{
    QMutexLocker lock(&_d->_mutex);
    if (_d->_test != NULL && _d->_result != NULL)
        _d->_test->run(_d->_result);

    _d->_test = NULL;
    _d->_result = NULL;
}
