#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

void CircularBuffer_Create(int capacity);

void CircularBuffer_Destroy();

int CircularBuffer_GetSize();

int CircularBuffer_GetCapacity();

void CircularBuffer_Enqueue(int numberToQueue);

int CircularBuffer_Dequeue();

#endif //CIRCULAR_BUFFER_H