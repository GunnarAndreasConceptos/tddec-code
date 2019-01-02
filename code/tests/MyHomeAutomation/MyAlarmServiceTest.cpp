extern "C"
{
#include "MyAlarmService.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(MyAlarmService)
{
    void setup()
    {
      MyAlarmService_Create();
    }

    void teardown()
    {
       MyAlarmService_Destroy();
    }

};

void testCallback(void)
{

}

TEST(MyAlarmService, Create)
{
    POINTERS_EQUAL(NULL, MyAlarmService_GetLastCallback());
    LONGS_EQUAL(-1, MyAlarmService_GetLastTimestamp());
}


TEST(MyAlarmService, ScheduleSingleAlarm)
{
    AlarmCallback CallBack = (AlarmCallback)testCallback;
    MyAlarmService_ScheduleAlarm(500, CallBack);
    POINTERS_EQUAL(CallBack, MyAlarmService_GetLastCallback());
    LONGS_EQUAL(500, MyAlarmService_GetLastTimestamp());
}
