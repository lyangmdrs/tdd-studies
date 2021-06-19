#include "LedDriver.h"

#define ALL_LEDS_ON 0xFFFF
#define ALL_LEDS_OFF ~(ALL_LEDS_ON)

static uint16_t * ledsAddress;

void LedDriver_Create(uint16_t * address)
{
    ledsAddress = address;
    *ledsAddress = ALL_LEDS_OFF;
}

void LedDriver_TurnOn(int ledNumber)
{
    *ledsAddress |= 1 << (ledNumber - 1);
}

void LedDriver_TurnOff(int ledNumber)
{
    *ledsAddress &= ~(1 << (ledNumber - 1));
}

void LedDriver_TurnAllOn(void)
{
    *ledsAddress = ALL_LEDS_ON;
}