#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include "stdint.h"

#define TRUE 1
#define FALSE 0

typedef int BOOL;

//Typeless declaration
typedef struct CircularBufferStruct *CircularBufferPtr;


void CircularBuffer_Create(CircularBufferPtr, int capacity);

void CircularBuffer_Destroy(CircularBufferPtr);

int CircularBuffer_GetSize(CircularBufferPtr);

int CircularBuffer_GetCapacity(CircularBufferPtr);

void CircularBuffer_Enqueue(CircularBufferPtr, int numberToQueue);

int CircularBuffer_Dequeue(CircularBufferPtr);

BOOL CircularBuffer_IsFull(CircularBufferPtr);

BOOL CircularBuffer_IsEmpty(CircularBufferPtr);

void CircularBuffer_Clear(CircularBufferPtr);

#endif //CIRCULAR_BUFFER_H