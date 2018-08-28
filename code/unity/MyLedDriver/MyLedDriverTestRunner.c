#include "unity_fixture.h"

TEST_GROUP_RUNNER(MyLedDriver)
{
    RUN_TEST_CASE(MyLedDriver, LedsOffAfterCreate);
}