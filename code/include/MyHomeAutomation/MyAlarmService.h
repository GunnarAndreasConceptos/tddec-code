#ifndef D_MyAlarmService_H
#define D_MyAlarmService_H

#include "MyMsTimeService.h"

typedef void (*AlarmCallback)(void);

void MyAlarmService_Create(void);
void MyAlarmService_Destroy(void);

void MyAlarmService_ScheduleAlarm(long msEpochTime, AlarmCallback cb);
AlarmCallback MyAlarmService_GetLastCallback(void);
long MyAlarmService_GetLastTimestamp(void);

#endif  /* D_MyAlarmService_H */
