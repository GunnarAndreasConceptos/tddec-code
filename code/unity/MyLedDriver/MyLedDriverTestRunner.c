#include "unity_fixture.h"

TEST_GROUP_RUNNER(MyLedDriver)
{
    RUN_TEST_CASE(MyLedDriver, LedsOffAfterCreate);
    RUN_TEST_CASE(MyLedDriver, TurnOnLedOne);
    RUN_TEST_CASE(MyLedDriver, TurnOffLedOne);
    RUN_TEST_CASE(MyLedDriver, TurnOnMultipleLeds);
    //RUN_TEST_CASE(MyLedDriver, TurnOffAnyLed);
    RUN_TEST_CASE(MyLedDriver, AllOn);
}