/*
 dynamically resizing array-based queue implementation
 current implementation does not support dynamic size reduction
 only dynamic size increase is supported
 */

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "queue.h"

/*return queue that can store capacity number of int elems
 */
arrayQueue_t* queue_init(int capacity)
{
    arrayQueue_t* q = (arrayQueue_t*)malloc(sizeof(arrayQueue_t));
    q->capacity = capacity;
    q->size = 0;
    q->queue = (int*)malloc(sizeof(int) * capacity);
    q->head = 0;
    q->tail = 0;
    
    return q;
}

/*add elem to queue; array doubles in size when
 queue is half-full
 */
void queue_add(arrayQueue_t* q, int val)
{
    assert(q->size < q->capacity);
    
    q->queue[q->tail] = val;
    (q->size)++;
    
    if (q->tail == (q->capacity - 1))
    {
        q->tail = 0;    //wrap around
    }
    else
    {
        (q->tail)++;
    }
    
    if (q->size == q->capacity/2)
    {
        q->queue = (int*)realloc(q->queue, sizeof(int) * (q->capacity * 2));
        q->capacity *= 2;
    }
}

/*remove elem from queue; return 0 if queue
 is already empty
 */
int queue_remove(arrayQueue_t* q)
{
    if (q->size == 0)
    {
        printf("queue empty\n");
        return 0;
    }
    
    int removeElem = q->queue[q->head];
    (q->size)--;
    (q->head)++;
    return removeElem;
}

/*return size (number of elems in queue)
 */
int queue_size(arrayQueue_t* q)
{
    return q->size;
}

/*return first elem in queue
 */
int queue_head(arrayQueue_t* q)
{
    return q->queue[q->head];
}

/*return true if queue is empty, false otherwise
 */
bool queue_isEmpty(arrayQueue_t* q)
{
    if (q->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*print all elems in queue
 */
void queue_print(arrayQueue_t* q)
{
    for (int i = q->head; i < q->size; i++)
    {
        if (i == q->capacity)
        {
            i = 0;  //wrap around
        }
        
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}


