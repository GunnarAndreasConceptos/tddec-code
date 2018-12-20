#include "MyLightScheduler.h"
#include "MyTimeService.h"
#include "MyLightController.h"

typedef enum {
    TURN_ON,
    TURN_OFF
} LightEvent;

typedef struct
{
    int id;
    int minuteOfDay;
    LightEvent event;
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

    if (scheduledEvent.event == TURN_ON)
        MyLightController_On(scheduledEvent.id);
    else if (scheduledEvent.event == TURN_OFF)
        MyLightController_Off(scheduledEvent.id);
}

static void scheduleEvent(int id, Day day, int minuteOfDay, LightEvent event) {
    scheduledEvent.id = id;
    scheduledEvent.minuteOfDay = minuteOfDay;
    scheduledEvent.event = event;
}

void MyLightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

void MyLightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}
