/*
dynamically resizing array-based stack implementation
*/

#ifndef stack_h
#define stack_h

#include <stdbool.h>

typedef struct arrayStack_t
{
    int capacity;
    int size;
    int* stack;
} arrayStack_t;

arrayStack_t* stack_init(int capacity);

void stack_push(arrayStack_t* s, int val);
int stack_pop(arrayStack_t* s);
int stack_size(arrayStack_t* s);
int stack_top(arrayStack_t* s);
bool stack_isEmpty(arrayStack_t* s);
void stack_print(arrayStack_t* s);

#endif /* stack_h */
