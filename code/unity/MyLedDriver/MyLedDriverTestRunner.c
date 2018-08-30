#include "unity_fixture.h"
#include "MyLedDriverTest.h"

static void RunAllTests()
{
    RUN_TEST_CASE(MyLedDriver, LedsOffAfterCreate);
    RUN_TEST_CASE(MyLedDriver, TurnOnLedOne);
    RUN_TEST_CASE(MyLedDriver, TurnOffLedOne);
    RUN_TEST_CASE(MyLedDriver, TurnOnMultipleLeds);
    RUN_TEST_CASE(MyLedDriver, TurnOffAnyLed);
    RUN_TEST_CASE(MyLedDriver, AllOn);
    RUN_TEST_CASE(MyLedDriver, InvertLogicIsApplied);
    RUN_TEST_CASE(MyLedDriver, LedMemoryIsNotReadable);
    RUN_TEST_CASE(MyLedDriver, UpperAndLowerBounds);
    RUN_TEST_CASE(MyLedDriver, OutOfBoundsTurnOnDoesNoHarm);
    RUN_TEST_CASE(MyLedDriver, OutOfBoundsTurnOffDoesNoHarm);
    RUN_TEST_CASE(MyLedDriver, OutOfBoundsTurnOnProducesRuntimeError);
    RUN_TEST_CASE(MyLedDriver, OutOfBoundsTurnOffProducesRuntimeError);
    RUN_TEST_CASE(MyLedDriver, IsOn);
    RUN_TEST_CASE(MyLedDriver, OutOfBoundsLedsAreAlwaysOff);
    RUN_TEST_CASE(MyLedDriver, IsOff);
    RUN_TEST_CASE(MyLedDriver, TurnOffMultipleLeds);
    RUN_TEST_CASE(MyLedDriver, AllOff);
    //This test is being ignored, but seems to cause test after also being ignored. Ensure this is at the end
    RUN_TEST_CASE(MyLedDriver, OutOfBoundsToDo);
}

TEST_GROUP_RUNNER(MyLedDriver)
{
    SetInvertLogic(0);
    RunAllTests();
    SetInvertLogic(1);
    RunAllTests();
}