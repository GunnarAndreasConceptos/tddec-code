#include "MyLightScheduler.h"
#include "MyTimeService.h"
#include "MyLightController.h"
#include "common.h"

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

#define MAX_EVENTS 128

static ScheduledLightEvent scheduledEvents[MAX_EVENTS];

void MyLightScheduler_Create(void)
{
    int i;
    for (i = 0; i < MAX_EVENTS; i++)
    {
        scheduledEvents[i].id = UNUSED;
    }

    MyTimeService_SetPeriodicAlarmInSeconds(60, MyLightScheduler_WakeUp);
}

void MyLightScheduler_Destroy(void)
{
    MyTimeService_CancelPeriodicAlarmInSeconds(60, MyLightScheduler_WakeUp);
}

static void operateLight(const ScheduledLightEvent * lightEvent)
{
    if (lightEvent->event == TURN_ON)
        MyLightController_On(lightEvent->id);
    else if (lightEvent->event == TURN_OFF)
        MyLightController_Off(lightEvent->id);

}

static int DoesLightRespontToday(const Time * time, int reactionDay) {
    int today = time->dayOfWeek;
    if (reactionDay == EVERYDAY)
        return TRUE;
    if (reactionDay == today)
        return TRUE;
    if (reactionDay == WEEKEND && (today == SATURDAY || today == SUNDAY))
        return TRUE;
    if (reactionDay == WEEKDAY && (today >= MONDAY && today <= FRIDAY))
        return TRUE;

    return FALSE;
}

static void processEventDueNow(const Time * time, const ScheduledLightEvent * lightEvent)
{
    int reactionDay = lightEvent->day;
    
    if (lightEvent->id == UNUSED)
        return;
    if(!DoesLightRespontToday(time, reactionDay))
        return;
    if (time->minuteOfDay != lightEvent->minuteOfDay)
        return;

    operateLight(lightEvent);
}


void MyLightScheduler_WakeUp(void)
{
    Time time;
    MyTimeService_GetTime(&time);

    int i;
    for (i = 0; i < MAX_EVENTS; i++)
    {
        processEventDueNow(&time, &scheduledEvents[i]);
    }
}

static int scheduleEvent(int id, Day day, int minuteOfDay, LightEvent event) {
    int i;

    if (id < 0 || id >= MAX_LIGHTS) {
        return LS_ID_OUT_OF_BOUNDS;
    }
    
    for (i = 0; i < MAX_EVENTS; i++)
    {
        if (scheduledEvents[i].id == UNUSED)
        {
            scheduledEvents[i].id = id;
            scheduledEvents[i].minuteOfDay = minuteOfDay;
            scheduledEvents[i].event = event;
            scheduledEvents[i].day = day;
            return LS_OK;
        }
    }
    return LS_TOO_MANY_EVENTS;

}

int MyLightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    
    return scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

int MyLightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    return scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}

void MyLightScheduler_ScheduleRemove(int id, Day day, int minuteOfDay)
{
    int i;
    for (i = 0; i < MAX_EVENTS; i++)
    {
        if (scheduledEvents[i].id == id
        && scheduledEvents[i].minuteOfDay == minuteOfDay
        && scheduledEvents[i].day == day)
        {
            scheduledEvents[i].id = UNUSED;
            return;
        }
    }
}