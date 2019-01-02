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

    void scheduleTestCallback(long msTime)
    {
        AlarmCallback callBack = (AlarmCallback)testCallback;
        MyAlarmService_ScheduleAlarm(msTime, callBack);
    }
};


TEST(MyAlarmService, Create)
{
    POINTERS_EQUAL(NULL, MyAlarmService_GetLastCallback());
    LONGS_EQUAL(-1, MyAlarmService_GetLastTimestamp());
}


TEST(MyAlarmService, ScheduleSingleAlarm)
{
    AlarmCallback callBack = (AlarmCallback)testCallback;
    MyAlarmService_ScheduleAlarm(500, callBack);

    POINTERS_EQUAL(callBack, MyAlarmService_GetLastCallback());
    LONGS_EQUAL(500, MyAlarmService_GetLastTimestamp());
}

TEST(MyAlarmService, ScheduledAlarmDoesNotRunBeforeTime)
{
    scheduleTestCallback(500);

    MyFakeMsTimeService_SetMilliSeconds(400);
    MyAlarmService_WakeUp();
    LONGS_EQUAL(0, callBackCounter);
}

TEST(MyAlarmService, ScheduledAlarmRunsOnTime)
{
    scheduleTestCallback(500);

    MyFakeMsTimeService_SetMilliSeconds(500);
    MyAlarmService_WakeUp();
    LONGS_EQUAL(1, callBackCounter);
}

TEST(MyAlarmService, ScheduledAlarmRunsAfterTime)
{
    scheduleTestCallback(500);

    MyFakeMsTimeService_SetMilliSeconds(501);
    MyAlarmService_WakeUp();
    LONGS_EQUAL(1, callBackCounter);
}
