#include "LedDriver.h"

static uint16_t * ledsAddress;
void LedDriver_Create(uint16_t * address)
{
    ledsAddress = address;
    *ledsAddress = 0;
}

void LedDriver_TurnOn(int ledNumber)
{
    *ledsAddress |= 1 << (ledNumber - 1);
}

void LedDriver_TurnOff(int ledNumber)
{
    *ledsAddress = 0;
}