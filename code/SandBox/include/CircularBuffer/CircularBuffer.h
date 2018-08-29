#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include "stdint.h"

#define TRUE 1
#define FALSE 0
typedef int BOOL;

void CircularBuffer_Create(int capacity);

void CircularBuffer_Destroy();

int CircularBuffer_GetSize();

int CircularBuffer_GetCapacity();

void CircularBuffer_Enqueue(int numberToQueue);

int CircularBuffer_Dequeue();

BOOL CircularBuffer_IsFull();

#endif //CIRCULAR_BUFFER_H