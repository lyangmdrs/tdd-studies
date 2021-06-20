/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "LedDriver.h"

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_LedsOffAfterCreate(void);
extern void test_TurnOnLedOne(void);
extern void test_TurnOffLedOne(void);
extern void test_TurnOnMultipleLeds(void);
extern void test_TunrAllOn(void);
extern void test_TurnOffAnyLed(void);
extern void test_LedMemoryIsNotReadable(void);
extern void test_UpperAndLowerBounds(void);
extern void test_TurnOnOutOfBoundsChangesNothing(void);
extern void test_TurnOffOutOfBoundsChangesNothing(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test/LedDriverTest.c");
  run_test(test_LedsOffAfterCreate, "test_LedsOffAfterCreate", 15);
  run_test(test_TurnOnLedOne, "test_TurnOnLedOne", 22);
  run_test(test_TurnOffLedOne, "test_TurnOffLedOne", 28);
  run_test(test_TurnOnMultipleLeds, "test_TurnOnMultipleLeds", 35);
  run_test(test_TunrAllOn, "test_TunrAllOn", 42);
  run_test(test_TurnOffAnyLed, "test_TurnOffAnyLed", 48);
  run_test(test_LedMemoryIsNotReadable, "test_LedMemoryIsNotReadable", 55);
  run_test(test_UpperAndLowerBounds, "test_UpperAndLowerBounds", 62);
  run_test(test_TurnOnOutOfBoundsChangesNothing, "test_TurnOnOutOfBoundsChangesNothing", 69);
  run_test(test_TurnOffOutOfBoundsChangesNothing, "test_TurnOffOutOfBoundsChangesNothing", 81);

  return UnityEnd();
}
