#ifndef D_MyTimeService_H
#define D_MyTimeService_H

#include "MyLightScheduler.h"

typedef struct Time
{
    int minuteOfDay;
    int dayOfWeek;
} Time;
void MyTimeService_GetTime(Time *);

#endif