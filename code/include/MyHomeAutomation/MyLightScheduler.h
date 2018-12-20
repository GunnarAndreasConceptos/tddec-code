#ifndef D_MyLightScheduler_H
#define D_MyLightScheduler_H

/**********************************************************
 *
 * MyLightScheduler is responsible for ...
 *
 **********************************************************/
typedef enum  {
    NONE=-1, EVERYDAY=10, WEEKDAY, WEEKEND,
    SUNDAY=1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
} Day;

enum {UNUSED = -1};

void MyLightScheduler_Create(void);
void MyLightScheduler_Destroy(void);

void MyLightScheduler_WakeUp(void);
void MyLightScheduler_ScheduleTurnOn(int id, Day day, int minute);
void MyLightScheduler_ScheduleTurnOff(int id, Day day, int minute);

#endif  /* D_FakeMyLightScheduler_H */
