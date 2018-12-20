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
    
    void checkLightState(int id, int level)
    {
      if(id == LIGHT_ID_UNKNOWN)
      {
        LONGS_EQUAL(id, MyLightControllerSpy_GetLastId());
        LONGS_EQUAL(level, MyLightControllerSpy_GetLastState());
      }
      else
      {
        LONGS_EQUAL(level, MyLightControllerSpy_GetLightState(id));
      }
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

  checkLightState(0, LIGHT_ON);
  checkLightState(31, LIGHT_OFF);
}


