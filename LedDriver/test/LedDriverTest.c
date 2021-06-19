#include "LedDriver.h"
#include "unity.h"

/*
    LedDriver Module Test
    [✔] - Create LEDs in off state;
    [✔] - Turn on a single LED;
    [✔] - Turn off a single LED;
*/

void setUp(void)
{
}

void tearDown(void)
{
}

void test_LedsOffAfterCreate(void)
{
    uint16_t virtualLeds = 0xFFFF;
    LedDriver_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void test_TurnOnLedOne(void)
{
    uint16_t virtualLeds;
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

void test_TurnOffLedOne(void)
{
    uint16_t virtualLeds;
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}