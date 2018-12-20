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


int MyLightControllerSpy_GetLastId(void)
{
    return lastId;
}

int MyLightControllerSpy_GetLastState(void)
{
    return lastState;
}
