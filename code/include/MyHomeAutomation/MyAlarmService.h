#ifndef D_MyAlarmService_H
#define D_MyAlarmService_H

typedef void (*AlarmCallback)(void);

void MyAlarmService_Create(void);
void MyAlarmService_Destroy(void);
AlarmCallback MyAlarmService_GetLastCallback(void);
int MyAlarmService_GetLastTimestamp(void);

#endif  /* D_MyAlarmService_H */
