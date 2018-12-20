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
    Day day;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;

void MyLightScheduler_Create(void)
{
    scheduledEvent.id = UNUSED;
}

void MyLightScheduler_Destroy(void)
{
}

static void operateLight(const ScheduledLightEvent * lightEvent)
{
    if (lightEvent->event == TURN_ON)
        MyLightController_On(lightEvent->id);
    else if (lightEvent->event == TURN_OFF)
        MyLightController_Off(lightEvent->id);

}


static void processEventDueNow(const Time * time, const ScheduledLightEvent * lightEvent)
{
    if (lightEvent->id == UNUSED)
        return;
    if (lightEvent->day != EVERYDAY)
        return;
    if (time->minuteOfDay != lightEvent->minuteOfDay)
        return;

    operateLight(lightEvent);
}


void MyLightScheduler_WakeUp(void)
{
    Time time;
    MyTimeService_GetTime(&time);

    processEventDueNow(&time, &scheduledEvent);
}

static void scheduleEvent(int id, Day day, int minuteOfDay, LightEvent event) {
    scheduledEvent.id = id;
    scheduledEvent.minuteOfDay = minuteOfDay;
    scheduledEvent.event = event;
    scheduledEvent.day = day;
}

void MyLightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

void MyLightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}
