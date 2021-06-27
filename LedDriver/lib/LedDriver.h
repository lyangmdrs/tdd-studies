#ifndef LEDDRIVER_H
#define LEDDRIVER_H

#include <stdint.h>
#include <stdbool.h>

void LedDriver_Create(uint16_t * address);
void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);
bool LedDriver_IsOn(int ledNumber);
void LedDriver_TurnAllOn(void);

#endif