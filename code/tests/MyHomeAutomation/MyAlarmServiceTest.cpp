extern "C"
{
#include "MyAlarmService.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(MyAlarmService)
{
    void setup()
    {
      MyAlarmService_Create();
    }

    void teardown()
    {
       MyAlarmService_Destroy();
    }
};

TEST(MyAlarmService, Create)
{
    POINTERS_EQUAL(NULL, MyAlarmService_GetLastCallback());
    LONGS_EQUAL(-1, MyAlarmService_GetLastTimestamp());
}


