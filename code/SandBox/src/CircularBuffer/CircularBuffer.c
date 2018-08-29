#include "CircularBuffer.h"

static int numberOfElements;

void CircularBuffer_Create(int capacity)
{
    numberOfElements = 0;
}

int CircularBuffer_GetSize()
{
    return numberOfElements;
}

int CircularBuffer_GetCapacity()
{
    return 4;
}

void CircularBuffer_Enqueue(int numberToQueue)
{
    numberOfElements++;
}