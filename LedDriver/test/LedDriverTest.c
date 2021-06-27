#include "LedDriver.h"
#include "unity.h"
#include "RuntimeErrorStub.h"

static uint16_t virtualLeds;

void setUp(void)
{
    LedDriver_Create(&virtualLeds);
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
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

void test_TurnOffLedOne(void)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void test_TurnOnMultipleLeds(void)
{
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x180, virtualLeds);
}

void test_TunrAllOn(void)
{
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
}

void test_TurnOffAnyLed(void)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(8);
    TEST_ASSERT_EQUAL_HEX16(0xFF7F, virtualLeds);
}

void test_LedMemoryIsNotReadable(void)
{
    virtualLeds = 0xFFFF;
    LedDriver_TurnOn(8);
    TEST_ASSERT_EQUAL_HEX16(0x80, virtualLeds);
}

void test_UpperAndLowerBounds(void)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, virtualLeds);
}

void test_TurnOnOutOfBoundsChangesNothing(void)
{
    LedDriver_TurnOn(-1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
    LedDriver_TurnOn(0);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
    LedDriver_TurnOn(17);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
    LedDriver_TurnOn(2352);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void test_TurnOffOutOfBoundsChangesNothing(void)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(-1);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(0);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
    LedDriver_TurnAllOn();
    LedDriver_TurnOn(17);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(2352);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
}

void test_OutOfBoudsProducesRuntimerError(void)
{
    LedDriver_TurnOn(-1);
    TEST_ASSERT_EQUAL_STRING("LED Driver: out-of-bouds LED!",
                             RuntimeErrorStub_GetLastError());
    TEST_ASSERT_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

void test_CheckIfLedIsOn(void)
{
    TEST_ASSERT_FALSE(LedDriver_IsOn(11));
    LedDriver_TurnOn(11);
    TEST_ASSERT_TRUE(LedDriver_IsOn(11));
}

void test_OutOfBoundLedsAreAlwaysOff(void)
{
    TEST_ASSERT_FALSE(LedDriver_IsOn(0));
    TEST_ASSERT_TRUE(LedDriver_IsOff(0));
    TEST_ASSERT_FALSE(LedDriver_IsOn(17));
    TEST_ASSERT_TRUE(LedDriver_IsOff(17));
    LedDriver_TurnAllOn();
    TEST_ASSERT_FALSE(LedDriver_IsOn(0));
    TEST_ASSERT_TRUE(LedDriver_IsOff(0));
    TEST_ASSERT_FALSE(LedDriver_IsOn(17));
    TEST_ASSERT_TRUE(LedDriver_IsOff(17));
}

void test_TurnAllOf(void)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnAllOff();
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

void test_CheckIfLedIsOff(void)
{
    TEST_ASSERT_TRUE(LedDriver_IsOff(7));
    LedDriver_TurnOn(7);
    TEST_ASSERT_FALSE(LedDriver_IsOff(7));
}