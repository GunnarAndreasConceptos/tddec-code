#include "MyAlarmService.h"
#include "common.h"


typedef struct Alarm {
    AlarmCallback cb;
    long msEpochTime;
} Alarm;

static Alarm alarm;

enum {
    ALARM_UNUSED = -1
};

void resetAlarm(void)
{
    alarm.cb = NULL;
    alarm.msEpochTime = ALARM_UNUSED;
}

void MyAlarmService_Create(void)
{
    resetAlarm();
}

void MyAlarmService_Destroy(void)
{

}
AlarmCallback MyAlarmService_GetLastCallback(void)
{
    return alarm.cb;
}

long MyAlarmService_GetLastTimestamp(void)
{
    return alarm.msEpochTime;
}

void MyAlarmService_ScheduleAlarm(long msEpochTime, AlarmCallback cb)
{
    alarm.cb = cb;
    alarm.msEpochTime = msEpochTime;
}

BOOL isAlarmValid(void)
{
    return (alarm.msEpochTime != ALARM_UNUSED && alarm.cb != NULL);
}

void MyAlarmService_WakeUp()
{
    if (!isAlarmValid())
    {
        return;
    }

    MsTime currentTime;
    MyMsTimeService_GetTime(&currentTime);

    if (currentTime.msec >= alarm.msEpochTime)
    {
        alarm.cb();
        resetAlarm();
    }
}