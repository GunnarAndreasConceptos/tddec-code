#include "MyLightScheduler.h"
#include "MyTimeService.h"
#include "MyLightController.h"

typedef struct
{
    int id;
    int minuteOfDay;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;

void MyLightScheduler_Create(void)
{
    scheduledEvent.id = UNUSED;
}

void MyLightScheduler_Destroy(void)
{
}


void MyLightScheduler_WakeUp(void)
{
    Time time;
    MyTimeService_GetTime(&time);

    if (scheduledEvent.id == UNUSED)
        return;

    if (time.minuteOfDay != scheduledEvent.minuteOfDay)
        return;

    MyLightController_On(scheduledEvent.id);
}

void MyLightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    scheduledEvent.id = id;
    scheduledEvent.minuteOfDay = minuteOfDay;
}