#include "HelperSuite.h"
#include "TestParameterizedTestCaller.h"
#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/ParameterizedTestCaller.h>

#include <iostream>


CPPUNIT_TEST_SUITE_NAMED_REGISTRATION( TestParameterizedTestCaller, 
                                       helperSuiteName() );

namespace {

class SimpleTest : public CPPUNIT_NS::TestFixture
{
public:

    void test(const int& i);
};

void SimpleTest::test(const int& i)
{
    std::cout << i;
}

}

TestParameterizedTestCaller::TestParameterizedTestCaller()
{
}


TestParameterizedTestCaller::~TestParameterizedTestCaller()
{
}

void 
TestParameterizedTestCaller::test1()
{
  {
    CPPUNIT_NS::ParameterizedTestCaller<SimpleTest, int> caller( "test1", 
                                                 &SimpleTest::test, 
                                                 { 1, 2, 3} );
    CPPUNIT_NS::TestResult m_result;
    caller.run( &m_result );

  } // Force destruction of the test caller.
}
