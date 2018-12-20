#include "MyLightControllerSpy.h"
#include <string.h>

static int lastId;
static int lastState;


static int lights[MAX_LIGHTS];

void MyLightController_Create(void)
{
    lastId = LIGHT_ID_UNKNOWN;
    lastState = LIGHT_STATE_UNKNOWN;
    memset(lights, LIGHT_STATE_UNKNOWN, sizeof lights);
}

void MyLightController_Destroy(void)
{
}

static void updateLights(int id, int state)
{
    lastId = id;
    lastState = state;
    lights[lastId] = lastState;
}

void MyLightController_On(int id)
{
    updateLights(id, LIGHT_ON);
}

void MyLightController_Off(int id)
{
    updateLights(id, LIGHT_OFF);
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
    return lights[id];
}