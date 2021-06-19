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
  run_test(test_LedsOffAfterCreate, "test_LedsOffAfterCreate", 20);
  run_test(test_TurnOnLedOne, "test_TurnOnLedOne", 27);
  run_test(test_TurnOffLedOne, "test_TurnOffLedOne", 33);
  run_test(test_TurnOnMultipleLeds, "test_TurnOnMultipleLeds", 40);

  return UnityEnd();
}
