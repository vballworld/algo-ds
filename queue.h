#ifndef queue_h
#define queue_h

#include <stdio.h>

typedef struct arrayQueue_t
{
    int capacity;
    int size;
    int head;
    int tail;
    int* queue;
} arrayQueue_t;

arrayQueue_t* queue_init(int capacity);
void queue_add(arrayQueue_t* q, int val);
int queue_remove(arrayQueue_t* q);
int queue_head(arrayQueue_t* q);
void queue_print(arrayQueue_t* q);

#endif /* queue_h */
