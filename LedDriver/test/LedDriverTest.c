#include "LedDriver.h"
#include "unity.h"

/*
    LedDriver Module Test
    []
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