#ifndef D_MyTimeService_H
#define D_MyTimeService_H

typedef enum  {
    SUNDAY=1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
} Day;

typedef struct Time
{
    int minuteOfDay;
    int dayOfWeek;
} Time;
void MyTimeService_GetTime(Time *);

#endif