#ifndef D_MyFakeTimeService_H
#define D_MyFakeTimeService_H

/**********************************************************
 *
 * MyFakeTimeService is responsible for ...
 *
 **********************************************************/

#include "MyTimeService.h"

enum {TIME_UNKNOWN = -1};
void MyFakeTimeService_Create(void);
void MyFakeTimeService_Destroy(void);

void MyFakeTimeService_SetMinute(int);
void MyFakeTimeService_SetDay(int);
MyWakeupCallback MyFakeTimeService_GetAlarmCallback(void);
int MyFakeTimeService_GetAlarmPeriod(void);

#endif  /* D_FakeMyFakeTimeService_H */
