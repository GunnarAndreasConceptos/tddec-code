#include "CircularBuffer.h"
#include <stdlib.h>

static int* buffer;
static int head;
static int tail;
static int bufferCapacity;

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

    FreeBufferIfSet();
    buffer = malloc(sizeof(int) * bufferCapacity);
}

void CircularBuffer_Destroy()
{
    FreeBufferIfSet();
}

int CircularBuffer_GetSize()
{
    return tail-head;
}

int CircularBuffer_GetCapacity()
{
    return bufferCapacity;
}

void CircularBuffer_Enqueue(int numberToQueue)
{
    //Copy the new element into the buffer
    buffer[tail] = numberToQueue;
    tail++;
}

int CircularBuffer_Dequeue()
{
    int numberToDequeue = buffer[head];
    head++;
    return numberToDequeue;
}