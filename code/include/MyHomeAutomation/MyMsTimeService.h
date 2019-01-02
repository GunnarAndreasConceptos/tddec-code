#ifndef D_MyMsTimeService_H
#define D_MyMsTimeService_H

/* Returns time in ms epoch*/
typedef struct MsTime
{
    long msec;
} MsTime;


void MyMsTimeService_GetTime(MsTime * time);

#endif