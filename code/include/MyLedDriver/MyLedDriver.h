#ifndef MY_LED_DRIVER_H
#define MY_LED_DRIVER_H

#include "stdint.h"

#define TRUE 1
#define FALSE 0
typedef int BOOL;

void MyLedDriver_Create(uint16_t* address, BOOL invertLogic);

void MyLedDriver_TurnOn(int ledNumber);

void MyLedDriver_TurnOff(int ledNumber);

void MyLedDriver_TurnAllOn();

BOOL MyLedDriver_IsOn(int ledNumber);

BOOL MyLedDriver_IsOff(int ledNumber);

void MyLedDriver_TurnAllOff();
#endif //MY_LED_DRIVER_H