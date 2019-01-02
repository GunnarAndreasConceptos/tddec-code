#include "MyAlarmService.h"
#include "common.h"


typedef struct Alarm {
    AlarmCallback cb;
    long msEpochTime;
} Alarm;

static Alarm alarm;

void MyAlarmService_Create(void)
{
    alarm.cb = NULL;
    alarm.msEpochTime = -1;
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

void MyAlarmService_WakeUp()
{
    MsTime currentTime;
    MyMsTimeService_GetTime(&currentTime);

    if (currentTime.msec == alarm.msEpochTime) {
        alarm.cb();
    }
}