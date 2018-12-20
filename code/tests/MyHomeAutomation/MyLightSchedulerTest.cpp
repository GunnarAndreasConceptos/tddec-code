extern "C"
{
#include "MyLightScheduler.h"
#include "MyLightControllerSpy.h"
#include "MyFakeTimeService.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(MyLightScheduler)
{
    void setup()
    {
      MyLightScheduler_Create();
      MyLightController_Create();

    }

    void teardown()
    {
      MyLightScheduler_Destroy();
      MyLightController_Destroy();
    }
};

TEST(MyLightScheduler, NoChangeToLightsDuringInitialization)
{
  LONGS_EQUAL(LIGHT_ID_UNKNOWN, MyLightControllerSpy_GetLastId());
  LONGS_EQUAL(LIGHT_STATE_UNKNOWN, MyLightControllerSpy_GetLastState());
}

TEST(MyLightScheduler, NoScheduleNothingHapens)
{
  MyFakeTimeService_SetDay(MONDAY);
  MyFakeTimeService_SetMinute(100);

  MyLightScheduler_WakeUp();

  LONGS_EQUAL(LIGHT_ID_UNKNOWN, MyLightControllerSpy_GetLastId());
  LONGS_EQUAL(LIGHT_STATE_UNKNOWN, MyLightControllerSpy_GetLastState());

}


TEST(MyLightScheduler, ScheduleOnEverydayNotTimeYet)
{
  MyLightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
  MyFakeTimeService_SetDay(MONDAY);
  MyFakeTimeService_SetMinute(1199);

  MyLightScheduler_WakeUp();

  LONGS_EQUAL(LIGHT_ID_UNKNOWN, MyLightControllerSpy_GetLastId());
  LONGS_EQUAL(LIGHT_STATE_UNKNOWN, MyLightControllerSpy_GetLastState());

}

TEST(MyLightScheduler, ScheduleOnEverydayItsTime)
{
  MyLightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
  MyFakeTimeService_SetDay(MONDAY);
  MyFakeTimeService_SetMinute(1200);

  MyLightScheduler_WakeUp();

  LONGS_EQUAL(3, MyLightControllerSpy_GetLastId());
  LONGS_EQUAL(LIGHT_ON, MyLightControllerSpy_GetLastState());

}