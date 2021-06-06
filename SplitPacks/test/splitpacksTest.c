#include "splitpacks.h"
#include "unity.h"
#include <string.h>

#define MESSAGE_SIZE 100
#define PADDING_CHAR '0'

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
    buildMessage(message, 24);
    expect(message);
    TEST_ASSERT_EQUAL_STRING(expected, message);
}