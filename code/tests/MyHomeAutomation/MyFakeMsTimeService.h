#ifndef D_MyFakeMsTimeService_H
#define D_MyFakeMsTimeService_H

#include "MyMsTimeService.h"

enum {TIME_UNKNOWN = -1};

void MyFakeMsTimeService_Create(void);
void MyFakeMsTimeService_Destroy(void);

#endif