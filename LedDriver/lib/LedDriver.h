#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#include <stdint.h>

void LedDriver_Create(uint16_t * address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
void LedDriver_TurnAllOn(void);
uint16_t convertLedNumberToBit(int ledNumber);
void updateHardware(void);

#endif