#include "CircularBuffer.h"
#include <stdlib.h>

static int* buffer;
static int head;
static int tail;
static int bufferCapacity;

void CircularBuffer_Create(int capacity)
{
    head = 0;
    tail = 0;
    bufferCapacity = capacity;

    if (buffer != NULL)
    {
        free(buffer);
    }

    buffer = malloc(sizeof(int) * bufferCapacity);
}

void CircularBuffer_Destroy()
{
    if (buffer != NULL)
    {
        free(buffer);
        buffer = NULL;
    }
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