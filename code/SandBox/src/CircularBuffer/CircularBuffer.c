#include "CircularBuffer.h"
#include <stdlib.h>

static int* buffer;
static int head;
static int tail;
static int bufferCapacity;
static int numOfElements;

static void FreeBufferIfSet()
{
    if (buffer != NULL)
    {
        free(buffer);
        buffer = NULL;
    }
}

void CircularBuffer_Create(int capacity)
{
    head = 0;
    tail = 0;
    bufferCapacity = capacity;
    numOfElements = 0;

    FreeBufferIfSet();
    buffer = malloc(sizeof(int) * bufferCapacity);
}

void CircularBuffer_Destroy()
{
    FreeBufferIfSet();
}

int CircularBuffer_GetSize()
{
    return numOfElements;
}

int CircularBuffer_GetCapacity()
{
    return bufferCapacity;
}

void CircularBuffer_Enqueue(int numberToQueue)
{
    buffer[head] = numberToQueue;

    //Need to move tail if we are overwriting stuff
    if (CircularBuffer_IsFull())
    {
        tail = (tail + 1) % (bufferCapacity);
    }
    else
    {
        numOfElements++;
    }

    head = (head + 1) % (bufferCapacity);
}

int CircularBuffer_Dequeue()
{
    int numberToDequeue = buffer[tail];
    tail = (tail + 1) % (bufferCapacity);

    if (!CircularBuffer_IsEmpty())
    {
        numOfElements--;
    }

    return numberToDequeue;
}

BOOL CircularBuffer_IsFull()
{
    return CircularBuffer_GetSize() == bufferCapacity;
}

BOOL CircularBuffer_IsEmpty()
{
    return CircularBuffer_GetSize() == 0;
}

void CircularBuffer_Clear()
{
    head = tail;
    numOfElements = 0;
}