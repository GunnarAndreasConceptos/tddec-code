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
      if(id == LIGHT_ID_UNKNOWN)
      {
        LONGS_EQUAL(id, MyLightControllerSpy_GetLastId());
        LONGS_EQUAL(level, MyLightControllerSpy_GetLastState());
      }
      else
      {
        LONGS_EQUAL(level, MyLightControllerSpy_GetLightState(id));
      }
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

TEST(MyLightScheduler, ScheduleWeekEndItsFriday)
{
  MyLightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
  setTimeTo(FRIDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(MyLightScheduler, ScheduleWeekEndItsSaturday)
{
  MyLightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
  setTimeTo(SATURDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(3, LIGHT_ON);
}

TEST(MyLightScheduler, ScheduleWeekEndItsSunday)
{
  MyLightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
  setTimeTo(SUNDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(3, LIGHT_ON);
}

TEST(MyLightScheduler, ScheduleWeekEndItsMonday)
{
  MyLightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
  setTimeTo(MONDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(MyLightScheduler, WeekdayScheduleNotOperatedOnSunday)
{
  MyLightScheduler_ScheduleTurnOn(3, WEEKDAY, 1200);
  setTimeTo(SUNDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(MyLightScheduler, ScheduleOnWeekdayAndItsMondayAndItsTime)
{
  MyLightScheduler_ScheduleTurnOn(3, WEEKDAY, 1200);
  setTimeTo(MONDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(3, LIGHT_ON);
}

TEST(MyLightScheduler, ScheduleOnWeekdayAndItsFridayAndItsTime)
{
  MyLightScheduler_ScheduleTurnOn(3, WEEKDAY, 1200);
  setTimeTo(FRIDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(3, LIGHT_ON);
}

TEST(MyLightScheduler, ScheduleOnWeekdayAndItsSaturdayAndItsTime)
{
  MyLightScheduler_ScheduleTurnOn(3, WEEKDAY, 1200);
  setTimeTo(SATURDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(MyLightScheduler, ScheduleTwoEventsAtTheSameTIme)
{
  MyLightScheduler_ScheduleTurnOn(3, SUNDAY, 1200);
  MyLightScheduler_ScheduleTurnOn(12, SUNDAY, 1200);
  setTimeTo(SUNDAY, 1200);
  MyLightScheduler_WakeUp();
  checkLightState(3, LIGHT_ON);
  checkLightState(12, LIGHT_ON);
}

TEST(MyLightScheduler, RejectsTooManyEvents)
{
  int i;
  for (i = 0; i < 128; i++) {
    LONGS_EQUAL(LS_OK, MyLightScheduler_ScheduleTurnOn(6, MONDAY, 600+i));
  }
  LONGS_EQUAL(LS_TOO_MANY_EVENTS, MyLightScheduler_ScheduleTurnOn(6, MONDAY, 600+i));
  LONGS_EQUAL(LS_TOO_MANY_EVENTS, MyLightScheduler_ScheduleTurnOff(6, MONDAY, 600+i));

}

TEST(MyLightScheduler, RemoveRecyclesScheduleSlot)
{
  int i;
  for (i = 0; i < 128; i++) {
    LONGS_EQUAL(LS_OK, MyLightScheduler_ScheduleTurnOn(6, MONDAY, 600+i));
  }
  MyLightScheduler_ScheduleRemove(6, MONDAY, 600);
  LONGS_EQUAL(LS_OK, MyLightScheduler_ScheduleTurnOn(13, MONDAY, 1000));
}


TEST_GROUP(MyLightSchedulerInitAndCleanup)
{
};

TEST(MyLightSchedulerInitAndCleanup, CreateStartsOneMinuteAlarm)
{
  MyLightScheduler_Create();
  POINTERS_EQUAL((void *)MyLightScheduler_WakeUp,
  (void *)MyFakeTimeService_GetAlarmCallback());
  LONGS_EQUAL(60, MyFakeTimeService_GetAlarmPeriod());
  MyLightScheduler_Destroy();
}

TEST(MyLightSchedulerInitAndCleanup, DestroyCancelsOneMinuteAlarm)
{
  MyLightScheduler_Create();
  MyLightScheduler_Destroy();
  POINTERS_EQUAL(NULL, (void *)MyFakeTimeService_GetAlarmCallback());
}