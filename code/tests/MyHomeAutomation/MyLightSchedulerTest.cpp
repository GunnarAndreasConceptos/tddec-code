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

    void setTimeTo(int day, int minuteOfDay)
    {
      MyFakeTimeService_SetDay(day);
      MyFakeTimeService_SetMinute(minuteOfDay);
    }

    void checkLightState(int id, int level)
    {
      LONGS_EQUAL(id, MyLightControllerSpy_GetLastId());
      LONGS_EQUAL(level, MyLightControllerSpy_GetLastState());
    }
};

TEST(MyLightScheduler, NoChangeToLightsDuringInitialization)
{
  checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(MyLightScheduler, NoScheduleNothingHapens)
{
  setTimeTo(MONDAY, 100);
  MyLightScheduler_WakeUp();
  checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}


TEST(MyLightScheduler, ScheduleOnEverydayNotTimeYet)
{
  MyLightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
  setTimeTo(MONDAY, 1199);
  MyLightScheduler_WakeUp();
  checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(MyLightScheduler, ScheduleOnEverydayItsTime)
{
  MyLightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
  setTimeTo(MONDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(3, LIGHT_ON);

}

TEST(MyLightScheduler, ScheduleOffEverydayItsTime)
{
  MyLightScheduler_ScheduleTurnOff(3, EVERYDAY, 1200);
  setTimeTo(MONDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(3, LIGHT_OFF);
}

TEST(MyLightScheduler, ScheduleTuesdayButItsMonday)
{
  MyLightScheduler_ScheduleTurnOn(3, TUESDAY, 1200);
  setTimeTo(MONDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(MyLightScheduler, ScheduleTuesdayAndItsTuesday)
{
  MyLightScheduler_ScheduleTurnOn(3, TUESDAY, 1200);
  setTimeTo(TUESDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(3, LIGHT_ON);
}