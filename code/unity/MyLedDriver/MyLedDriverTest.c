#include "unity_fixture.h"
#include "stdint.h"
#include "MyLedDriver.h"
#include "MyRuntimeErrorStub.h"

TEST_GROUP(MyLedDriver);

static uint16_t virtualLeds;
static BOOL invertLogic = FALSE;


static void TestAllLedsAreOn()
{
    int i = 0; 
    for (i = 1; i <= 16; i++)
    {
        TEST_ASSERT_TRUE(MyLedDriver_IsOn(i));
    }
}

static void TestAllLedsAreOff()
{
    int i = 0; 
    for (i = 1; i <= 16; i++)
    {
        TEST_ASSERT_TRUE(MyLedDriver_IsOff(i));
    }
}

void SetInvertLogic(int invert)
{
    invertLogic = (BOOL)invert;
}

TEST_SETUP(MyLedDriver)
{
    MyLedDriver_Create(&virtualLeds, invertLogic);
}

TEST_TEAR_DOWN(MyLedDriver)
{

}

TEST(MyLedDriver, LedsOffAfterCreate)
{
    MyLedDriver_Create(&virtualLeds, invertLogic);
    TestAllLedsAreOff();
}

TEST(MyLedDriver, TurnOnLedOne)
{
    MyLedDriver_TurnOn(1);
    TEST_ASSERT_TRUE(MyLedDriver_IsOn(1));
}

TEST(MyLedDriver, TurnOffLedOne)
{
    MyLedDriver_TurnOn(1);
    MyLedDriver_TurnOff(1);
    TEST_ASSERT_TRUE(MyLedDriver_IsOff(1));
}

TEST(MyLedDriver, TurnOnMultipleLeds)
{
    MyLedDriver_TurnOn(9);
    MyLedDriver_TurnOn(8);
    TEST_ASSERT_TRUE(MyLedDriver_IsOn(9));
    TEST_ASSERT_TRUE(MyLedDriver_IsOn(8));
}

TEST(MyLedDriver, AllOn)
{
    MyLedDriver_TurnAllOn();
    TestAllLedsAreOn();
}

TEST(MyLedDriver, TurnOffAnyLed)
{
    MyLedDriver_TurnAllOn();
    MyLedDriver_TurnOff(8);
    TEST_ASSERT_TRUE(MyLedDriver_IsOff(8));
    TEST_ASSERT_TRUE(MyLedDriver_IsOn(9));
}

TEST(MyLedDriver, InvertLogicIsApplied)
{
    if (invertLogic)
    {
        virtualLeds = 0;
    }
    else
    {
        virtualLeds = 0xffff;
    }

    MyLedDriver_TurnOn(8);
    MyLedDriver_TurnOn(9);

    if (invertLogic)
    {
        TEST_ASSERT_EQUAL_HEX16((~0x180)&0xffff, virtualLeds);
    }
    else
    {
        TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
    }
}


//We now that the led memory is not supposed to be readable
//This test ensures our implementation simulates this by not reading from virtualLeds directly.
TEST(MyLedDriver, LedMemoryIsNotReadable)
{
    //We test here that setting virtualLeds variable in the test does not affect the internal leds state of the led driver.
    if (invertLogic)
    {
        virtualLeds = 0;
    }
    else
    {
        virtualLeds = 0xffff;
    }

    MyLedDriver_TurnOn(8);
    MyLedDriver_TurnOn(9);

    TEST_ASSERT_TRUE(MyLedDriver_IsOn(8));
    TEST_ASSERT_TRUE(MyLedDriver_IsOn(9));
    TEST_ASSERT_TRUE(MyLedDriver_IsOff(10));
}

TEST(MyLedDriver, UpperAndLowerBounds)
{
    MyLedDriver_TurnOn(1);
    MyLedDriver_TurnOn(16);
    TEST_ASSERT_TRUE(MyLedDriver_IsOn(1));
    TEST_ASSERT_TRUE(MyLedDriver_IsOn(16));
    TEST_ASSERT_TRUE(MyLedDriver_IsOff(9));
}

TEST(MyLedDriver, OutOfBoundsTurnOnDoesNoHarm)
{
    MyLedDriver_TurnOn(-1);
    MyLedDriver_TurnOn(0);
    MyLedDriver_TurnOn(17);
    MyLedDriver_TurnOn(3141);
    TestAllLedsAreOff();
}

TEST(MyLedDriver, OutOfBoundsTurnOffDoesNoHarm)
{
    MyLedDriver_TurnAllOn();
    MyLedDriver_TurnOff(-1);
    MyLedDriver_TurnOff(0);
    MyLedDriver_TurnOff(17);
    MyLedDriver_TurnOff(3141);
    TestAllLedsAreOn();
}

TEST(MyLedDriver, OutOfBoundsTurnOnProducesRuntimeError)
{
    MyLedDriver_TurnOn(-1);
    TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED",
        MyRuntimeErrorStub_GetLastError());
    TEST_ASSERT_EQUAL(-1, MyRuntimeErrorStub_GetLastParameter());
    MyRuntimeErrorStub_Reset();
}

TEST(MyLedDriver, OutOfBoundsTurnOffProducesRuntimeError)
{
    MyLedDriver_TurnOff(-1);
    TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bounds LED",
        MyRuntimeErrorStub_GetLastError());
    TEST_ASSERT_EQUAL(-1, MyRuntimeErrorStub_GetLastParameter());
}


IGNORE_TEST(MyLedDriver, OutOfBoundsToDo)
{
    /* TODO: What should we do during runtime? */
}

TEST(MyLedDriver, IsOn)
{
    TEST_ASSERT_FALSE(MyLedDriver_IsOn(11));
    MyLedDriver_TurnOn(11);
    TEST_ASSERT_TRUE(MyLedDriver_IsOn(11));
}

TEST(MyLedDriver, OutOfBoundsLedsAreAlwaysOff)
{
    TEST_ASSERT_TRUE(MyLedDriver_IsOff(0));
    TEST_ASSERT_TRUE(MyLedDriver_IsOff(17));
    TEST_ASSERT_FALSE(MyLedDriver_IsOn(0));
    TEST_ASSERT_FALSE(MyLedDriver_IsOn(17));
}

TEST(MyLedDriver, IsOff)
{
    TEST_ASSERT_TRUE(MyLedDriver_IsOff(12));
    MyLedDriver_TurnOn(12);
    TEST_ASSERT_FALSE(MyLedDriver_IsOff(12));
}

TEST(MyLedDriver, TurnOffMultipleLeds)
{
    MyLedDriver_TurnAllOn();
    MyLedDriver_TurnOff(9);
    MyLedDriver_TurnOff(8);
    TEST_ASSERT_TRUE(MyLedDriver_IsOff(9));
    TEST_ASSERT_TRUE(MyLedDriver_IsOff(8));
    TEST_ASSERT_TRUE(MyLedDriver_IsOn(10));
}

TEST(MyLedDriver, AllOff)
{
    MyLedDriver_TurnAllOn();
    MyLedDriver_TurnAllOff();
    TestAllLedsAreOff();
}