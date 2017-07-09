/*
dynamically resizing array-based stack implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

void push(arrayStack_t* s, int val)
{
    assert(s->size < s->capacity);  //array should resize proactively when it is half full

    s->stack[s->size] = val;
    (s->size)++;

    /*resize if half full
     */
    if (s->size == (s->capacity/2))
    {
        s->stack = (int*)realloc(s->stack, sizeof(int) * (s->capacity * 2));
        s->capacity *= 2;
    }
}

int pop(arrayStack_t* s)
{
    if (s->size == 0)
    {
        //nothing to pop
        printf("stack empty\n");
        return 0;
    }

    int popVal = s->stack[s->size - 1];
    (s->size)--;
    return popVal;
}

int size(arrayStack_t* s)
{
    return s->size;
}

int top(arrayStack_t* s)
{
    return s->stack[s->size - 1];
}

bool isEmpty(arrayStack_t* s)
{
    if (s->size == 0)
    {
        return true;    //is empty
    }
    else
    {
        return false;   //not empty
    }
}

void printStack(arrayStack_t* s)
{
    for (int i = 0 ; i < s->size; i++)
    {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

arrayStack_t* initStack(int capacity)
{
    arrayStack_t* s = (arrayStack_t*)malloc(sizeof(arrayStack_t));
    s->size = 0;
    s->capacity = capacity;
    s->stack = (int*)malloc(sizeof(int) * capacity);

    return s;
}