#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include "stdint.h"

#define TRUE 1
#define FALSE 0

typedef int BOOL;

/*
NB! This circular buffer only works on one static instance.
To support instances from outside, change interface so that we have an ABT that clients can hold and use create on.
I am to lazy to add this functionality and will focus on the TTD parts of this project 
*/

void CircularBuffer_Create(int capacity);

void CircularBuffer_Destroy();

int CircularBuffer_GetSize();

int CircularBuffer_GetCapacity();

void CircularBuffer_Enqueue(int numberToQueue);

int CircularBuffer_Dequeue();

BOOL CircularBuffer_IsFull();

BOOL CircularBuffer_IsEmpty();

void CircularBuffer_Clear();

#endif //CIRCULAR_BUFFER_H