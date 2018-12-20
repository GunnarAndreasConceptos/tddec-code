extern "C"
{
#include "MyLightControllerSpy.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(MyLightControllerSpy)
{
    void setup()
    {
      MyLightController_Create();
    }

    void teardown()
    {
       MyLightController_Destroy();
    }
};

TEST(MyLightControllerSpy, Create)
{
  LONGS_EQUAL(LIGHT_ID_UNKNOWN, MyLightControllerSpy_GetLastId());
  LONGS_EQUAL(LIGHT_STATE_UNKNOWN, MyLightControllerSpy_GetLastState());
}

TEST(MyLightControllerSpy, RememberTheLastLightIdControlled)
{
  MyLightController_On(10);
  LONGS_EQUAL(10, MyLightControllerSpy_GetLastId());
  LONGS_EQUAL(LIGHT_ON, MyLightControllerSpy_GetLastState());
}


TEST(MyLightControllerSpy, RememberAllLightStates)
{
  MyLightController_On(0);
  MyLightController_Off(31);

  LONGS_EQUAL(LIGHT_ON, MyLightControllerSpy_GetLightState(0));
  LONGS_EQUAL(LIGHT_OFF, MyLightControllerSpy_GetLightState(31));
}


