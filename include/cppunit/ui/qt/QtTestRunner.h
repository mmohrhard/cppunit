#ifndef CPPUNIT_QTTESTRUNNER_H
#define CPPUNIT_QTTESTRUNNER_H

#include <QScopedPointer>

#include <cppunit/Portability.h>
#include <cppunit/ui/qt/Config.h>

CPPUNIT_NS_BEGIN

class Test;

/*!
 * \brief Qt test runner.
 * \ingroup ExecutingTest
 *
 * This test runner uses the Qt GUI framework for running and displaying registered tests.
 *
 * Here is an example of usage:
 * \code
 * #include <cppunit/extensions/TestFactoryRegistry.h>
 * #include <cppunit/ui/qt/TestRunner.h>
 *
 * void main(int argc, char*argv[])
 * {
 *     QApplication app(argc, argv);
 *
 *     CppUnit::QtTestRunner runner;
 *     runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
 *     runner.run(true);
 *
 *     return app.exec();
 * }
 * \endcode
 */
class QTTESTRUNNER_API QtTestRunner
{
    Q_DISABLE_COPY(QtTestRunner)

public:
    /*!
     * \brief Constructs a TestRunner object.
     */
    QtTestRunner();

    /*!
     * \brief Destructor.
     */
    ~QtTestRunner();

    /*!
     * \brief Runs the specified test (and all of its child tests)
     * \param autorun When set to \c true the tests are automatically run the first time
     */
    void run(bool autorun = false);

    /*!
     * \brief Adds a (top-level) test to the list of tests to run
     * \param test A test that shall be executed
     */
    void addTest(Test *test);

private:
    QScopedPointer<class QtTestRunnerPrivate> _d;
};

CPPUNIT_NS_END

#endif  // CPPUNIT_QTTESTRUNNER_H
