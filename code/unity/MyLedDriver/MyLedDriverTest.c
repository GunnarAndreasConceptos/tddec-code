#include "unity_fixture.h"
#include "stdint.h"

TEST_GROUP(MyLedDriver);

TEST_SETUP(MyLedDriver)
{

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