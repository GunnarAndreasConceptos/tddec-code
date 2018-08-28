
#include "unity_fixture.h"
#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer);

TEST_SETUP(CircularBuffer)
{
    CircularBuffer_Create(4);
}

TEST_TEAR_DOWN(CircularBuffer)
{
}

TEST(CircularBuffer, ListEmptyOnCreate)
{
    int numberOfElementsInList = CircularBuffer_GetSize();
    TEST_ASSERT_EQUAL_INT(0, numberOfElementsInList);
}

TEST(CircularBuffer, QueryListCapacity)
{
    int listCapacity = CircularBuffer_GetCapacity();
    TEST_ASSERT_EQUAL_INT(4, listCapacity);
}

TEST(CircularBuffer, EnqueueToList)
{
    CircularBuffer_Enqueue(1);
    TEST_ASSERT_EQUAL_INT(1, CircularBuffer_GetSize());
}   