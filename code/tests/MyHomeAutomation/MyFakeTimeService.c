#include "MyFakeTimeService.h"
#include "common.h"

static Time fakeTime;

typedef struct {
    MyWakeupCallback cb;
    int period;
} Alarm;

static Alarm fakeAlarm;

void MyFakeTimeService_Create(void)
{
    fakeTime.dayOfWeek = TIME_UNKNOWN;
    fakeTime.minuteOfDay = TIME_UNKNOWN;
}

void MyFakeTimeService_Destroy(void)
{
}


void MyFakeTimeService_SetMinute(int minute) 
{
    fakeTime.minuteOfDay = minute;
}

void MyFakeTimeService_SetDay(int day)
{
    fakeTime.dayOfWeek = day;
}

void MyTimeService_GetTime(Time *time)
{
    time->dayOfWeek = fakeTime.dayOfWeek;
    time->minuteOfDay = fakeTime.minuteOfDay;
}

int MyFakeTimeService_GetAlarmPeriod(void)
{
    return fakeAlarm.period;
}

MyWakeupCallback MyFakeTimeService_GetAlarmCallback(void) 
{
    return fakeAlarm.cb;
}

void MyTimeService_SetPeriodicAlarmInSeconds(int seconds, MyWakeupCallback callback)
{
    fakeAlarm.period = seconds;
    fakeAlarm.cb = callback;
}

void MyTimeService_CancelPeriodicAlarmInSeconds(int seconds, MyWakeupCallback callback)
{
    if (fakeAlarm.cb == callback && fakeAlarm.period == seconds)
    {
        fakeAlarm.cb = NULL;
        fakeAlarm.period = 0;
    }
}
