#include "MyAlarmService.h"
#include "common.h"


typedef struct Alarm {
    AlarmCallback cb;
    long msEpochTime;
} Alarm;


static Alarm alarm;
static Alarm scheduledAlarms[MAX_ALARMS];

enum {
    ALARM_UNUSED = -1
};

void resetAlarm(Alarm *alarm)
{
    alarm->cb = NULL;
    alarm->msEpochTime = ALARM_UNUSED;
}

void MyAlarmService_Create(void)
{
    resetAlarm(&alarm);
    int i;
    for (i = 0; i < MAX_ALARMS; i++)
    {
        resetAlarm(&scheduledAlarms[i]);
    }
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

    int i;
    for (i = 0; i < MAX_ALARMS; i++)
    {
        if (scheduledAlarms[i].msEpochTime == ALARM_UNUSED)
        {
            scheduledAlarms[i].msEpochTime = msEpochTime;
            scheduledAlarms[i].cb = cb;
            return;
        }
    }
}

BOOL isAlarmValid(Alarm *alarm)
{
    return (alarm->msEpochTime != ALARM_UNUSED && alarm->cb != NULL);
}

void MyAlarmService_WakeUp()
{

    MsTime currentTime;
    MyMsTimeService_GetTime(&currentTime);

    int i;
    for (i = 0; i < MAX_ALARMS; i++)
    {
        Alarm* currentAlarm = &scheduledAlarms[i];
        if (isAlarmValid(currentAlarm))
        {
            if (currentTime.msec >= currentAlarm->msEpochTime)
            {
                currentAlarm->cb();
                resetAlarm(currentAlarm);
            }
        }
    }
}