#include "MyFakeTimeService.h"


static Time fakeTime;
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
    return 60;
}

MyWakeupCallback MyFakeTimeService_GetAlarmCallback(void) 
{
    return 0;
}