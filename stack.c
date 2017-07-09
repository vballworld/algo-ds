/*
dynamically resizing array-based stack implementation
current implementation does not support dynamic size reduction
only dynamic size increase is supported
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

/*return stack that can store capacity number of int elems
*/
arrayStack_t* stack_init(int capacity)
{
    arrayStack_t* s = (arrayStack_t*)malloc(sizeof(arrayStack_t));
    s->size = 0;
    s->capacity = capacity;
    s->stack = (int*)malloc(sizeof(int) * capacity);

    return s;
}

/*push elem to stack; array doubles in size when
stack is half-full
*/
void stack_push(arrayStack_t* s, int val)
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

/*pop elem from stack; return 0 if stack
is already empty
*/
int stack_pop(arrayStack_t* s)
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

/*return size (number of elems in stack)
*/
int stack_size(arrayStack_t* s)
{
    return s->size;
}

/*return top elem in stack
*/
int stack_top(arrayStack_t* s)
{
    return s->stack[s->size - 1];
}

/*return true if stack is empty, false otherwise
*/
bool stack_isEmpty(arrayStack_t* s)
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

/*print all elems in stack
*/
void stack_print(arrayStack_t* s)
{
    for (int i = 0 ; i < s->size; i++)
    {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}


