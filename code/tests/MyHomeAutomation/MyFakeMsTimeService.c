#include "MyFakeMsTimeService.h"


void MyFakeMsTimeService_Create(void)
{

}

void MyFakeMsTimeService_Destroy(void)
{

}

void MyMsTimeService_GetTime(MsTime * time)
{
    time->msec = TIME_UNKNOWN;
}

void MyFakeMsTimeService_SetMilliSeconds(long msec)
{
    
}