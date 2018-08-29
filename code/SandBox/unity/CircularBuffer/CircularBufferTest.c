
#include "unity_fixture.h"
#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer);

static const int bufferCapacity = 4;

TEST_SETUP(CircularBuffer)
{
    CircularBuffer_Create(bufferCapacity);
}

TEST_TEAR_DOWN(CircularBuffer)
{
    CircularBuffer_Destroy();
}

TEST(CircularBuffer, ListEmptyOnCreate)
{
    TEST_ASSERT_EQUAL_INT(0, CircularBuffer_GetSize());
}

TEST(CircularBuffer, QueryListCapacity)
{
    TEST_ASSERT_EQUAL_INT(bufferCapacity, CircularBuffer_GetCapacity());
}

TEST(CircularBuffer, EnqueueToList)
{
    CircularBuffer_Enqueue(1);
    TEST_ASSERT_EQUAL_INT(1, CircularBuffer_GetSize());
}

TEST(CircularBuffer, DequeueFromList)
{
    CircularBuffer_Enqueue(2);
    int dequedValue = CircularBuffer_Dequeue();
    TEST_ASSERT_EQUAL_INT(0, CircularBuffer_GetSize());
    TEST_ASSERT_EQUAL_INT(2, dequedValue);
}

TEST(CircularBuffer, EnqueueManyToList)
{
    CircularBuffer_Enqueue(1);
    CircularBuffer_Enqueue(2);
    CircularBuffer_Enqueue(3);
    TEST_ASSERT_EQUAL_INT(3, CircularBuffer_GetSize());
}

TEST(CircularBuffer, DequeueManyToList)
{
    CircularBuffer_Enqueue(1);
    CircularBuffer_Enqueue(2);
    CircularBuffer_Enqueue(3);

    int dequedValue = CircularBuffer_Dequeue();
    dequedValue = CircularBuffer_Dequeue();
    TEST_ASSERT_EQUAL_INT(1, CircularBuffer_GetSize());
    TEST_ASSERT_EQUAL_INT(2, dequedValue);
}

TEST(CircularBuffer, NewCapacityTest)
{
    CircularBuffer_Create(5);
    TEST_ASSERT_EQUAL_INT(5, CircularBuffer_GetCapacity());
}

TEST(CircularBuffer, DetectListIsFull)
{
    TEST_ASSERT_FALSE(CircularBuffer_IsFull());
    int i;
    for (i = 0; i < bufferCapacity; i++)
    {
        CircularBuffer_Enqueue(i);
    }

    TEST_ASSERT_TRUE(CircularBuffer_IsFull());
}

TEST(CircularBuffer, DetectListIsEmpty)
{
    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty());
    CircularBuffer_Enqueue(0);
    TEST_ASSERT_FALSE(CircularBuffer_IsEmpty());
}

TEST(CircularBuffer, ClearList)
{
    CircularBuffer_Enqueue(0);
    CircularBuffer_Enqueue(1);
    CircularBuffer_Clear();
    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty());
}  