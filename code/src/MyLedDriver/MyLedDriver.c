#include "MyLedDriver.h"

enum 
{
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON    
};

static uint16_t* ledsAddress;

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

void MyLedDriver_Create(uint16_t *address)
{
    ledsAddress = address;
    *ledsAddress = ALL_LEDS_OFF;
}

void MyLedDriver_Destroy(void)
{

}

void MyLedDriver_TurnOn(int ledNumber)
{
    *ledsAddress |= convertLedNumberToBit(ledNumber);
}

void MyLedDriver_TurnOff(int ledNumber)
{
    *ledsAddress &= ~(convertLedNumberToBit(ledNumber));
}

void MyLedDriver_TurnAllOn()
{
    *ledsAddress = ALL_LEDS_ON;
}