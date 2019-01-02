#include "MyFakeMsTimeService.h"

static MsTime localTime;

void MyFakeMsTimeService_Create(void)
{
    localTime.msec = TIME_UNKNOWN;
}

void MyFakeMsTimeService_Destroy(void)
{

}

void MyMsTimeService_GetTime(MsTime * time)
{
    time->msec = localTime.msec;
}

void MyFakeMsTimeService_SetMilliSeconds(long msec)
{
    localTime.msec = msec;
}