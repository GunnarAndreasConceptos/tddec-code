#ifndef MY_LED_DRIVER_H
#define MY_LED_DRIVER_H

#include "stdint.h"

void MyLedDriver_Create(uint16_t* address);

void MyLedDriver_TurnOn(int ledNumber);
#endif //MY_LED_DRIVER_H