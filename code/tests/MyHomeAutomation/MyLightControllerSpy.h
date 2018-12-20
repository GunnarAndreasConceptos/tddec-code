#ifndef D_MyLightControllerSpy_H
#define D_MyLightControllerSpy_H

/**********************************************************
 *
 * MyLightControllerSpy is responsible for ...
 *
 **********************************************************/
#include "MyLightController.h"

enum 
{
    LIGHT_ID_UNKNOWN = -1, LIGHT_STATE_UNKNOWN = -1,
    LIGHT_OFF = 0, LIGHT_ON = 1
};

int MyLightControllerSpy_GetLightState(int id);
int MyLightControllerSpy_GetLastId(void);
int MyLightControllerSpy_GetLastState(void);

#endif  /* D_FakeMyLightControllerSpy_H */
