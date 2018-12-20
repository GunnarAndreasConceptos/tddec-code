extern "C"
{
#include "MyLightScheduler.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(MyLightScheduler)
{
    void setup()
    {
      MyLightScheduler_Create();
    }

    void teardown()
    {
       MyLightScheduler_Destroy();
    }
};

//Will implement code for this test later
/*TEST(MyLightScheduler, ScheduleOnEverydayNotTimeYet)
{
  MyLightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
  MyFakeTimeService_SetDay(MONDAY);
  MyFakeTimeService_SetMinute(1199);

  MyLightScheduler_Wakeup();

  LONGS_EQUAL(LIGHT_ID_UNKNOWN, MyLightControllerSpy_GetLastId());
  LONGS_EQUAL(LIGHT_STATE_UNKNOWN, MyLightControllerSpy_GetLastState());

}*/

