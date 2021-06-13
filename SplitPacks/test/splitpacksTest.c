#include "splitpacks.h"
#include "unity.h"
#include <string.h>

#define MESSAGE_SIZE 100
#define PADDING_CHAR '\0'

static char message[MESSAGE_SIZE];
static const char *expected;

void setUp(void)
{
    memset(message, PADDING_CHAR, sizeof message);
}

void tearDown(void)
{
}

static void expect(const char * s)
{
    expected = s;
}

void test_MessageBuilding(void)
{
    expect("ABCDEFGHIJKLMNOPQRSTUVWX");
    buildMessage(message, DATA_SIZE);
    TEST_ASSERT_EQUAL_STRING(expected, message);
}

void test_PostMemoryCorruption(void)
{
    expect(PADDING_CHAR);
    buildMessage(message, DATA_SIZE);
    TEST_ASSERT_EQUAL_CHAR(PADDING_CHAR, message[DATA_SIZE]);
}