
#include "unity_fixture.h"
#include "CircularBuffer.h"

TEST_GROUP(CircularBuffer);

static const int bufferCapacity = 4;
static CircularBufferPtr buffer;

TEST_SETUP(CircularBuffer)
{
    buffer = CircularBuffer_Create(bufferCapacity);
}

TEST_TEAR_DOWN(CircularBuffer)
{
    CircularBuffer_Destroy(buffer);
}

TEST(CircularBuffer, ListEmptyOnCreate)
{
    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(buffer));
}

TEST(CircularBuffer, ListNotFullOnCreate)
{
    TEST_ASSERT_FALSE(CircularBuffer_IsFull(buffer));
}


TEST(CircularBuffer, QueryListCapacity)
{
    TEST_ASSERT_EQUAL_INT(bufferCapacity, CircularBuffer_GetCapacity(buffer));
}

TEST(CircularBuffer, EnqueueToList)
{
    CircularBuffer_Enqueue(buffer, 1);
    TEST_ASSERT_EQUAL_INT(1, CircularBuffer_GetSize(buffer));
}

TEST(CircularBuffer, DequeueFromList)
{
    CircularBuffer_Enqueue(buffer, 2);
    int dequedValue = CircularBuffer_Dequeue(buffer);
    TEST_ASSERT_EQUAL_INT(0, CircularBuffer_GetSize(buffer));
    TEST_ASSERT_EQUAL_INT(2, dequedValue);
}

TEST(CircularBuffer, EnqueueManyToList)
{
    CircularBuffer_Enqueue(buffer, 1);
    CircularBuffer_Enqueue(buffer, 2);
    CircularBuffer_Enqueue(buffer, 3);
    TEST_ASSERT_EQUAL_INT(3, CircularBuffer_GetSize(buffer));
}

TEST(CircularBuffer, DequeueManyToList)
{
    CircularBuffer_Enqueue(buffer, 1);
    CircularBuffer_Enqueue(buffer, 2);
    CircularBuffer_Enqueue(buffer, 3);

    int dequedValue = CircularBuffer_Dequeue(buffer);
    dequedValue = CircularBuffer_Dequeue(buffer);
    TEST_ASSERT_EQUAL_INT(1, CircularBuffer_GetSize(buffer));
    TEST_ASSERT_EQUAL_INT(2, dequedValue);
}

TEST(CircularBuffer, NewCapacityTest)
{
    CircularBufferPtr newBuffer = CircularBuffer_Create(5);
    TEST_ASSERT_EQUAL_INT(5, CircularBuffer_GetCapacity(newBuffer));
    CircularBuffer_Destroy(newBuffer);
}

TEST(CircularBuffer, DetectListIsFull)
{
    TEST_ASSERT_FALSE(CircularBuffer_IsFull(buffer));
    int i;
    for (i = 0; i < CircularBuffer_GetCapacity(buffer); i++)
    {
        CircularBuffer_Enqueue(buffer, i);
    }

    TEST_ASSERT_TRUE(CircularBuffer_IsFull(buffer));
}

TEST(CircularBuffer, ToFullToEmptyToFull)
{
    int i;
    for (i = 0; i < CircularBuffer_GetCapacity(buffer); i++)
    {
        CircularBuffer_Enqueue(buffer, i);
    }

    TEST_ASSERT_TRUE(CircularBuffer_IsFull(buffer));

    for (i = 0; i < CircularBuffer_GetCapacity(buffer); i++)
    {
        CircularBuffer_Dequeue(buffer);
    }

    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(buffer));

    for (i = 0; i < CircularBuffer_GetCapacity(buffer); i++)
    {
        CircularBuffer_Enqueue(buffer, i);
    }

    TEST_ASSERT_TRUE(CircularBuffer_IsFull(buffer));
}   


TEST(CircularBuffer, DetectListIsEmpty)
{
    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Enqueue(buffer, 0);
    TEST_ASSERT_FALSE(CircularBuffer_IsEmpty(buffer));
    CircularBuffer_Dequeue(buffer);
    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(buffer));
}

TEST(CircularBuffer, ClearList)
{
    CircularBuffer_Enqueue(buffer, 0);
    CircularBuffer_Enqueue(buffer, 1);
    CircularBuffer_Clear(buffer);
    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(buffer));
} 

TEST(CircularBuffer, EnqueueWrapByDouble)
{
    int i;
    int lastValueAdded = 0;
    for (i = 0; i < CircularBuffer_GetCapacity(buffer)*2; i++)
    {
        CircularBuffer_Enqueue(buffer, i);
        lastValueAdded = i;
    }

    TEST_ASSERT_TRUE(CircularBuffer_IsFull(buffer));

    int lastValueRetrieved;
    for (i = 0; i < CircularBuffer_GetCapacity(buffer); i++)
    {
        lastValueRetrieved = CircularBuffer_Dequeue(buffer);
    }

    TEST_ASSERT_TRUE(CircularBuffer_IsEmpty(buffer));
    TEST_ASSERT_EQUAL_INT(lastValueAdded, lastValueRetrieved);
}

TEST(CircularBuffer, DequeueReturnsZeroOnEmptyList)
{
    int emptyListValue = CircularBuffer_Dequeue(buffer);
    TEST_ASSERT_EQUAL_INT(0, emptyListValue);
}

