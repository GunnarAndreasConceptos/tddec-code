
#include "unity_fixture.h"
#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer);

TEST_SETUP(CircularBuffer)
{
}

TEST_TEAR_DOWN(CircularBuffer)
{
}

TEST(CircularBuffer, ListEmptyOnCreate)
{
    CircularBuffer_Create(1);
    int numberOfElementsInList = CircularBuffer_Size();
    TEST_ASSERT_EQUAL(0, numberOfElementsInList);
}

TEST(CircularBuffer, QueryListCapacity)
{
    CircularBuffer_Create(4);
    int listCapacity = CircularBuffer_GetCapacity();
    TEST_ASSERT_EQUAL_INT(4, listCapacity);
}

