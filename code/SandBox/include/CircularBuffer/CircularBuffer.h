#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

void CircularBuffer_Create(int capacity);

int CircularBuffer_GetSize();

int CircularBuffer_GetCapacity();

void CircularBuffer_Enqueue(int numberToQueue);

#endif //CIRCULAR_BUFFER_H