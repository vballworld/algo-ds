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

arrayStack_t* initStack(int capacity);

void push(arrayStack_t* s, int val);
int pop(arrayStack_t* s);
int size(arrayStack_t* s);
int top(arrayStack_t* s);
bool isEmpty(arrayStack_t* s);
void printStack(arrayStack_t* s);

#endif /* stack_h */
