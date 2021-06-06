#include "util.h"
#include "unity.h"
#include <string.h>

static char output[100];
static const char * expected;

void setUp(void)
{
    memset(output, 0xaa, sizeof output);
    expected = "";
}

void tearDown(void)
{
}

static void expect(const char * s)
{
    expected = s;
}

static void given(int charsWriten)
{
    TEST_ASSERT_EQUAL(strlen(expected), charsWriten);
    TEST_ASSERT_EQUAL_STRING(expected, output);
    TEST_ASSERT_EQUAL_CHAR(0xaa, output[strlen(expected) + 1]);
}

void test_NoFormatOperations(void)
{
    expect("hey");
    given(sprintf(output, "hey"));
}

void test_InsertString(void)
{
    expect("opa povo\n");
    given(sprintf(output, "opa %s\n", "povo"));
}