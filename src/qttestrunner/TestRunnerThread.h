#ifndef TESTRUNNERTHREAD_H
#define TESTRUNNERTHREAD_H

#include <QScopedPointer>
#include <QThread>

#include <cppunit/Test.h>
#include <cppunit/TestResult.h>

/**
 * \class TestRunnerThread
 * \brief This class represents the thread used to run the test cases asynchronously.
 */
class TestRunnerThread : public QThread
{
    Q_OBJECT
    Q_DISABLE_COPY(TestRunnerThread)

    typedef CPPUNIT_NS::Test Test;
    typedef CPPUNIT_NS::TestResult TestResult;

public:
    /*!
     * \brief Constructs a TestRunner thread object.
     * \param parent A pointer to a parent QObject
     */
    TestRunnerThread(QObject *parent = 0);

    /*!
     * \brief Destructor
     */
    ~TestRunnerThread();

public slots:
    /*!
     * \brief Stops a running test
     */
    void adviseToStop();

    /*!
     * \brief Sets information for the test to run and the output result
     * \param testToRun A pointer to a Test which should be run
     * \param result A pointer to a TestResult object.
     */
    void setTestInformation(Test *testToRun, TestResult *result);

private:
    void run();

private:
    QScopedPointer<class TestRunnerThreadPrivate> _d;
};

#endif // TESTRUNNERTHREAD_H
