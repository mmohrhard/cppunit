#ifndef TESTCALLERTEST_H
#define TESTCALLERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestSuite.h>

class TestParameterizedTestCaller : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( TestParameterizedTestCaller );
  CPPUNIT_TEST( test1 );
  CPPUNIT_TEST_SUITE_END();

public:
  TestParameterizedTestCaller();
  ~TestParameterizedTestCaller();

  void test1();

};

#endif  // TESTCALLERTEST_H
