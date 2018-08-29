#include "CircularBuffer.h"
#include <stdlib.h>

static int* buffer;
static int head;
static int tail;

void CircularBuffer_Create(int capacity)
{
    head = 0;
    tail = 0;
    buffer = malloc(sizeof(int) * capacity);
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
    return 4;
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