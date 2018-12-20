#ifndef D_MyTimeService_H
#define D_MyTimeService_H

#include "MyLightScheduler.h"

typedef struct Time
{
    int minuteOfDay;
    int dayOfWeek;
} Time;

typedef void (*MyWakeupCallback)(void);

void MyTimeService_GetTime(Time *);
void MyTimeService_SetPeriodicAlarmInSeconds(
        int seconds, MyWakeupCallback);
void MyTimeService_CancelPeriodicAlarmInSeconds(
        int seconds, MyWakeupCallback);


#endif