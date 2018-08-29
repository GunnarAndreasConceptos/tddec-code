#include "MyLedDriver.h"
#include "MyRuntimeError.h"

enum 
{
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON    
};

static uint16_t* ledsAddress;
static uint16_t ledsImage;

static void updateHardware()
{
    *ledsAddress = ledsImage;
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

void MyLedDriver_Create(uint16_t *address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

void MyLedDriver_Destroy(void)
{

}

void MyLedDriver_TurnOn(int ledNumber)
{
    if (ledNumber <= 0 || ledNumber > 16)
    {
        MYRUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
        return;
    }

    ledsImage |= convertLedNumberToBit(ledNumber);
    updateHardware();
}

void MyLedDriver_TurnOff(int ledNumber)
{
    if (ledNumber <= 0 || ledNumber > 16)
    {
        return;
    }

    ledsImage &= ~(convertLedNumberToBit(ledNumber));
    updateHardware();
}

void MyLedDriver_TurnAllOn()
{
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}