#include "unity_fixture.h"

TEST_GROUP_RUNNER(CircularBuffer)
{
    RUN_TEST_CASE(CircularBuffer, ListEmptyOnCreate);
    RUN_TEST_CASE(CircularBuffer, QueryListCapacity);
    RUN_TEST_CASE(CircularBuffer, EnqueueToList);
    RUN_TEST_CASE(CircularBuffer, DequeueFromList);
    RUN_TEST_CASE(CircularBuffer, EnqueueManyToList);
    RUN_TEST_CASE(CircularBuffer, DequeueManyToList);
    RUN_TEST_CASE(CircularBuffer, NewCapacityTest);
}
