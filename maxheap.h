/*array-based max heap implementation
 current implementation does not support dynamic resizing of array
 */

#ifndef maxheap_h
#define maxheap_h

#include <stdio.h>

typedef struct maxheap_t
{
    int size;
    int capacity;
    int* heap;
} maxheap_t;

maxheap_t* maxheap_init(int capacity);
void maxheap_insert(maxheap_t* h, int val);
int maxheap_deleteMax(maxheap_t* h);
void maxheap_print(maxheap_t* h);;

#endif /* maxheap_h */
