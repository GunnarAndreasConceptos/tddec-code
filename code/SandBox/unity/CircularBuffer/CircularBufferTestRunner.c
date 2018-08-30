#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBuffer)
{
    RUN_TEST_CASE(CircularBuffer, ListEmptyOnCreate);
    RUN_TEST_CASE(CircularBuffer, ListNotFullOnCreate);
    RUN_TEST_CASE(CircularBuffer, QueryListCapacity);
    RUN_TEST_CASE(CircularBuffer, EnqueueToList);
    RUN_TEST_CASE(CircularBuffer, DequeueFromList);
    RUN_TEST_CASE(CircularBuffer, EnqueueManyToList);
    RUN_TEST_CASE(CircularBuffer, DequeueManyToList);
    RUN_TEST_CASE(CircularBuffer, NewCapacityTest);
    RUN_TEST_CASE(CircularBuffer, DetectListIsFull);
    RUN_TEST_CASE(CircularBuffer, DetectListIsEmpty);
    RUN_TEST_CASE(CircularBuffer, ToFullToEmptyToFull)
    RUN_TEST_CASE(CircularBuffer, ClearList);
    RUN_TEST_CASE(CircularBuffer, EnqueueWrapByDouble);
    RUN_TEST_CASE(CircularBuffer, DequeueReturnsZeroOnEmptyList);
}
