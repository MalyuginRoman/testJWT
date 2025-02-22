#include <iostream>
#include "math.h"
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/extensions/HelperMacros.h>
#include <jwt/jwt.hpp>

class TestJWT : public CPPUNIT_NS::TestCase
{
CPPUNIT_TEST_SUITE(TestJWT);
  CPPUNIT_TEST(testJWT_1);
CPPUNIT_TEST_SUITE_END();

public:
void setUp(void) {}
void tearDown(void){}

protected:
  void testJWT_1(void)
  {
#ifdef testJWT
    std::cout << "Start testJWT_1" << std::endl;
    std::cout << jwt::decode("eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXUyJ9.eyJpc3MiOiJhdXRoMCJ9.AbIJTDMFc7yUa5MhvcP03nJPyCPzZtQcGEp-zWfOkEE") << std::endl;
    std::cout << "Close testJWT_1" << std::endl;
#endif
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestJWT);

int main()
{
CPPUNIT_NS::TestResult controller;

CPPUNIT_NS::TestResultCollector result;
controller.addListener(&result);

CPPUNIT_NS::BriefTestProgressListener progress;
controller.addListener(&progress);

CPPUNIT_NS::TestRunner runner;
runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
runner.run(controller);

return result.wasSuccessful() ? 0 : 1;
}
