#include "MyLedDriver.h"

static uint16_t* ledsAddress;

void MyLedDriver_Create(uint16_t *address)
{
    ledsAddress = address;
    *ledsAddress = 0;
}

void MyLedDriver_Destroy(void)
{

}

void MyLedDriver_TurnOn(int ledNumber)
{
    *ledsAddress |= (1 << (ledNumber -1));
}

void MyLedDriver_TurnOff(int ledNumber)
{
    *ledsAddress = 0;
}
