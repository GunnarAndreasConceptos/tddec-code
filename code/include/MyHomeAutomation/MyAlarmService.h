#ifndef D_MyAlarmService_H
#define D_MyAlarmService_H

#include "MyMsTimeService.h"

enum{MAX_ALARMS = 128};
typedef void (*AlarmCallback)(void);

void MyAlarmService_Create(void);
void MyAlarmService_Destroy(void);

void MyAlarmService_ScheduleAlarm(long msEpochTime, AlarmCallback cb);
AlarmCallback MyAlarmService_GetLastCallback(void);
long MyAlarmService_GetLastTimestamp(void);
void MyAlarmService_WakeUp(void);

#endif  /* D_MyAlarmService_H */
