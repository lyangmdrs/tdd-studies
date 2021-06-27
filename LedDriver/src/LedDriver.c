#include "LedDriver.h"
#include "RuntimeErrorStub.h"

#define ALL_LEDS_ON 0xFFFF
#define ALL_LEDS_OFF 0
#define LOWER_LED_BOUND 1
#define UPPER_LED_BOUND 16

static uint16_t * ledsAddress;
static uint16_t ledsImage;

static uint16_t convertLedNumberToBit(int ledNumber)
{
    return (1 << (ledNumber - 1));
}

static void updateHardware(void)
{
    *ledsAddress = ledsImage;
}

static bool isValidLedNumber(int ledNumber)
{
    return ((ledNumber >= LOWER_LED_BOUND) && (ledNumber <= UPPER_LED_BOUND));
}

void LedDriver_Create(uint16_t * address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

void LedDriver_TurnOn(int ledNumber)
{
    if(!isValidLedNumber(ledNumber))
    {
        RUNTIME_ERROR("LED Driver: out-of-bouds LED!", ledNumber);
        return;
    }

    ledsImage |= convertLedNumberToBit(ledNumber);
    updateHardware();
}

void LedDriver_TurnOff(int ledNumber)
{
    if(!isValidLedNumber(ledNumber))
    {
        RUNTIME_ERROR("LED Driver: out-of-bouds LED!", ledNumber);
        return;
    }

    ledsImage &= ~convertLedNumberToBit(ledNumber);
    updateHardware();
}

void LedDriver_TurnAllOn(void)
{
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}
