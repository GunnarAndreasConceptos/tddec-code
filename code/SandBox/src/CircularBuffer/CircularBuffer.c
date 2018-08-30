#include "CircularBuffer.h"
#include <stdlib.h>

struct CircularBufferStruct
{
    int head;
    int tail;
    int bufferCapacity;
    int numOfElements;
    int *buffer;
};

static void FreeBufferIfSet(CircularBufferPtr circularBuffer)
{

    if (circularBuffer != NULL)
    {
        if (circularBuffer->buffer != NULL)
        {
            free(circularBuffer->buffer);
        }
        free(circularBuffer);
        circularBuffer = NULL;
    }
}

static void IncrementHead(CircularBufferPtr circularBuffer)
{
    circularBuffer->head = (circularBuffer->head + 1) % (circularBuffer->bufferCapacity);
}

static void IncrementTail(CircularBufferPtr circularBuffer)
{
    circularBuffer->tail = (circularBuffer->tail + 1) % (circularBuffer->bufferCapacity);
}


CircularBufferPtr CircularBuffer_Create(int capacity)
{
    CircularBufferPtr circularBuffer = malloc(sizeof(struct CircularBufferStruct));

    circularBuffer->head = 0;
    circularBuffer->tail = 0;
    circularBuffer->bufferCapacity = capacity;
    circularBuffer->numOfElements = 0;
    circularBuffer->buffer = malloc(sizeof(int) * capacity);

    return circularBuffer;
}

void CircularBuffer_Destroy(CircularBufferPtr circularBuffer)
{
    FreeBufferIfSet(circularBuffer);
}

int CircularBuffer_GetSize(CircularBufferPtr circularBuffer)
{
    return circularBuffer->numOfElements;
}

int CircularBuffer_GetCapacity(CircularBufferPtr circularBuffer)
{
    return circularBuffer->bufferCapacity;
}

void CircularBuffer_Enqueue(CircularBufferPtr circularBuffer, int numberToQueue)
{
    circularBuffer->buffer[circularBuffer->head] = numberToQueue;

    //Need to move tail if we are overwriting stuff
    if (CircularBuffer_IsFull(circularBuffer))
    {
        IncrementTail(circularBuffer);
    }
    else
    {
        circularBuffer->numOfElements++;
    }
    IncrementHead(circularBuffer);
}

int CircularBuffer_Dequeue(CircularBufferPtr circularBuffer)
{
    if (CircularBuffer_IsEmpty(circularBuffer))
    {
        return 0;
    }

    int numberToDequeue = circularBuffer->buffer[circularBuffer->tail];
    IncrementTail(circularBuffer);
    circularBuffer->numOfElements--;
    return numberToDequeue;
}

BOOL CircularBuffer_IsFull(CircularBufferPtr circularBuffer)
{
    return CircularBuffer_GetSize(circularBuffer) == circularBuffer->bufferCapacity;
}

BOOL CircularBuffer_IsEmpty(CircularBufferPtr circularBuffer)
{
    return CircularBuffer_GetSize(circularBuffer) == 0;
}

void CircularBuffer_Clear(CircularBufferPtr circularBuffer)
{
    circularBuffer->head = circularBuffer->tail;
    circularBuffer->numOfElements = 0;
}