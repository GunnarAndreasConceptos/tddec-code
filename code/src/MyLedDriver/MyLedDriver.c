#include "MyLedDriver.h"
#include "MyRuntimeError.h"

enum 
{
    ALL_LEDS_ON = ~0,
    ALL_LEDS_OFF = ~ALL_LEDS_ON    
};

enum
{
    FIRST_LED = 1,
    LAST_LED = 16
};

static uint16_t* ledsAddress;
static uint16_t ledsImage;

static void updateHardware()
{
    *ledsAddress = ledsImage;
}

static BOOL isLedOutOfBounds(int ledNumber)
{
    return (ledNumber < FIRST_LED || (ledNumber > LAST_LED));
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return 1 << (ledNumber - 1);
}

static void setLedImageBit(int ledNumber)
{
    ledsImage |= convertLedNumberToBit(ledNumber);
}

static void clearLedImageBit(int ledNumber)
{
    ledsImage &= ~(convertLedNumberToBit(ledNumber));
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
    if (isLedOutOfBounds(ledNumber))
    {
        MYRUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
        return;
    }

    setLedImageBit(ledNumber);
    updateHardware();
}

void MyLedDriver_TurnOff(int ledNumber)
{
    if (isLedOutOfBounds(ledNumber))
    {
        return;
    }

    clearLedImageBit(ledNumber);
    updateHardware();
}

void MyLedDriver_TurnAllOn()
{
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}

BOOL MyLedDriver_IsOn(int ledNumber)
{
    return ledsImage & (convertLedNumberToBit(ledNumber));
}