extern "C"
{
#include "MyFakeMsTimeService.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(MyFakeMsTimeService){
    void setup(){
        MyFakeMsTimeService_Create();
    }

    void teardown()
    {
        MyFakeMsTimeService_Destroy();
    }
};

TEST(MyFakeMsTimeService, Create)
{
    MsTime time;
    MyMsTimeService_GetTime(&time);

    LONGS_EQUAL(TIME_UNKNOWN, time.msec);
}

TEST(MyFakeMsTimeService, SetTime)
{
    MyFakeMsTimeService_SetMilliSeconds(5000);

    MsTime time;
    MyMsTimeService_GetTime(&time);

    LONGS_EQUAL(5000, time.msec);
}