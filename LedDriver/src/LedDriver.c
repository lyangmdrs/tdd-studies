#include "LedDriver.h"

#define ALL_LEDS_ON 0xFFFF
#define ALL_LEDS_OFF 0
#define LOWER_LED_BOUND 0
#define UPPER_LED_BOUND 16

static uint16_t * ledsAddress;
static uint16_t ledsImage;

static void updateHardware(void)
{
    *ledsAddress = ledsImage;
}

void LedDriver_Create(uint16_t * address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

void LedDriver_TurnOn(int ledNumber)
{
    if((LOWER_LED_BOUND > ledNumber) || (ledNumber > UPPER_LED_BOUND))
        return;

    ledsImage |= 1 << (ledNumber - 1);
    updateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
    ledsImage &= ~(1 << (ledNumber - 1));
    updateHardware();
}

void LedDriver_TurnAllOn(void)
{
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}