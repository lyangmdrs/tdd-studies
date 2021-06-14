#include "splitpacks.h"
#include "unity.h"
#include <string.h>
#include <stdlib.h>
/*
    SplitPacks Module Test:
    [x] The module recieves a message and splits it in a determinated number of messages (packets)
    [x] The packets must be null-terminated
    [x] The module recieves a determinated number of packets and join all of them in a message
*/

static char** output;
static const char* expected;

void setUp(void)
{
    output = malloc(2 * sizeof(char*));
    for (int i = 0; i < 2; i++)
    {
        output[i] = malloc(6 * sizeof(char));
    }
}

void tearDown(void)
{
}

static void expect(const char * s)
{
    expected = s;
}

void test_MessageSplitng(void)
{
    int length = 10;
    int numPacks = 2;
    
    splitMessage("ABCDEFGHIJ", length, numPacks, output);

    expect("ABCDE\0");
    TEST_ASSERT_EQUAL_STRING(expected, output[0]);

    expect("FGHIJ\0");
    TEST_ASSERT_EQUAL_STRING(expected, output[1]);
}

void test_NullTermination(void)
{
    int length = 10;
    int numPacks = 2;
    
    splitMessage("ABCDEFGHIJ", length, numPacks, output);

    TEST_ASSERT_EQUAL_CHAR('\0', output[0][5]);
    TEST_ASSERT_EQUAL_CHAR('\0', output[1][5]);
}

void test_JunctionOfPackets(void)
{
    int length = 10;
    int numPacks = 2;
    
    char* message;

    message = malloc((length + 1) * sizeof(char));

    splitMessage("ABCDEFGHIJ", length, numPacks, output);
    joinPackets(output, numPacks, length/numPacks, message);

    expect("ABCDEFGHIJ");

    TEST_ASSERT_EQUAL_STRING(expected, message);
}

void test_JunctionOfPacketsNullTermination(void)
{
    int length = 10;
    int numPacks = 2;
    
    char* message;

    message = malloc((length + 1) * sizeof(char));

    splitMessage("ABCDEFGHIJ", length, numPacks, output);
    joinPackets(output, numPacks, length/numPacks, message);

    TEST_ASSERT_EQUAL_CHAR('\0', message[length]);
}