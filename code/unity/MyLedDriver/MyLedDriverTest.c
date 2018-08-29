#include "unity_fixture.h"
#include "stdint.h"
#include "MyLedDriver.h"

TEST_GROUP(MyLedDriver);

static uint16_t virtualLeds;

TEST_SETUP(MyLedDriver)
{
    MyLedDriver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(MyLedDriver)
{

}

TEST(MyLedDriver, LedsOffAfterCreate)
{
    uint16_t virtualLeds = 0xffff;
    MyLedDriver_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(MyLedDriver, TurnOnLedOne)
{
    MyLedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(MyLedDriver, TurnOffLedOne)
{
    MyLedDriver_TurnOn(1);
    MyLedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(MyLedDriver, TurnOnMultipleLeds)
{
    //Tests should be documenting, and bit 9 and 8 give:
    //0001 1000 000, which gives a recognizable pattern to verify in hex: 0x180
    MyLedDriver_TurnOn(9);
    MyLedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}

TEST(MyLedDriver, AllOn)
{
    MyLedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xffff, virtualLeds);
}

TEST(MyLedDriver, TurnOffAnyLed)
{
    MyLedDriver_TurnAllOn();
    MyLedDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(0xff7f, virtualLeds);
}