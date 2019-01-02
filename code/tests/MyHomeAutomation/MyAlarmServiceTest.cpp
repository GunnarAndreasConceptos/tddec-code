extern "C"
{
#include "MyAlarmService.h"
#include "MyFakeMsTimeService.h"

}

#include "CppUTest/TestHarness.h"

static int callBackCounter = 0;
void testCallback(void)
{
    callBackCounter++;
}

TEST_GROUP(MyAlarmService)
{
    void setup()
    {
        callBackCounter = 0;
        MyAlarmService_Create();
    }

    void teardown()
    {
       MyAlarmService_Destroy();
    }

};


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

TEST(MyAlarmService, ScheduledAlarmDoesNotRunBeforeTime)
{
    AlarmCallback CallBack = (AlarmCallback)testCallback;
    MyAlarmService_ScheduleAlarm(500, CallBack);

    MyFakeMsTimeService_SetMilliSeconds(400);
    MyAlarmService_WakeUp();
    LONGS_EQUAL(0, callBackCounter);
}

TEST(MyAlarmService, ScheduledAlarmRunsOnTime)
{
    AlarmCallback CallBack = (AlarmCallback)testCallback;
    MyAlarmService_ScheduleAlarm(500, CallBack);

    MyFakeMsTimeService_SetMilliSeconds(500);
    MyAlarmService_WakeUp();
    LONGS_EQUAL(1, callBackCounter);
}
