#include "MyLightControllerSpy.h"

static int lastId;
static int lastState;

void MyLightController_Create(void)
{
    lastId = LIGHT_ID_UNKNOWN;
    lastState = LIGHT_STATE_UNKNOWN;
}

void MyLightController_Destroy(void)
{
}

void MyLightController_On(int id)
{
    lastId = id;
    lastState = LIGHT_ON;
}

void MyLightController_Off(int id)
{
    lastId = id;
    lastState = LIGHT_OFF;
}

int MyLightControllerSpy_GetLastId(void)
{
    return lastId;
}

int MyLightControllerSpy_GetLastState(void)
{
    return lastState;
}

int MyLightControllerSpy_GetLightState(int id)
{
    return LIGHT_STATE_UNKNOWN;
}