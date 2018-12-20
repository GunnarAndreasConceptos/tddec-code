extern "C"
{
#include "MyFakeTimeService.h"
#include "MyLightControllerSpy.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(MyFakeTimeService)
{
    void setup()
    {
      MyFakeTimeService_Create();
    }

    void teardown()
    {
       MyFakeTimeService_Destroy();
    }
};

TEST(MyFakeTimeService, Create)
{
  Time time;
  MyTimeService_GetTime(&time);

  LONGS_EQUAL(TIME_UNKNOWN, time.minuteOfDay);
  LONGS_EQUAL(TIME_UNKNOWN, time.dayOfWeek);
}


TEST(MyFakeTimeService, Set)
{
  Time time;
  MyFakeTimeService_SetMinute(42);
  MyFakeTimeService_SetDay(SATURDAY);

  MyTimeService_GetTime(&time);

  LONGS_EQUAL(42, time.minuteOfDay);
  LONGS_EQUAL(SATURDAY, time.dayOfWeek);
}