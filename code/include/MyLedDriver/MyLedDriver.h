#ifndef MY_LED_DRIVER_H
#define MY_LED_DRIVER_H

#include "stdint.h"

#define TRUE 1
#define FALSE 0
typedef int BOOL;

void MyLedDriver_Create(uint16_t* address);

void MyLedDriver_TurnOn(int ledNumber);

void MyLedDriver_TurnOff(int ledNumber);

void MyLedDriver_TurnAllOn();
#endif //MY_LED_DRIVER_H