/*array-based max heap implementation
 current implementation does not support dynamic resizing of array
 */

#include <stdlib.h>
#include "maxheap.h"
#include "utilities.h"

/*static prototypes
 */
static void maxheap_swim(maxheap_t* h);
static void maxheap_sink(maxheap_t* h);

/*return maxheap whose capacity is set to capacity
 */
maxheap_t* maxheap_init(int capacity)
{
    maxheap_t* h = (maxheap_t*)malloc(sizeof(maxheap_t));
    h->size = 0;    //first elem insert into heap[1] (skip heap[0])
    h->capacity = capacity;
    h->heap = (int*)malloc(sizeof(int) * capacity);
    
    return h;
}

/*swim up the recently inserted elem from the tail of the heap
 */
static void maxheap_swim(maxheap_t* h)
{
    /*swim up as long as curr elem is bigger than the parent
     */
    int currIndex = h->size;
    int currVal = h->heap[currIndex];
    
    while ((currVal > h->heap[currIndex/2]) && (currIndex > 1))
    {
        array_swap(h->heap, currIndex, currIndex/2);
        currIndex /= 2;
    }
}

/*insert an elem into maxheap
 */
void maxheap_insert(maxheap_t* h, int val)
{
    if (h->size == h->capacity)
    {
        printf("heap is full\n");
        return;
    }
    
    h->heap[h->size + 1] = val;
    (h->size)++;
    
    maxheap_swim(h);
}

/*sink down the new root of heap
 */
static void maxheap_sink(maxheap_t* h)
{
    int currIndex = 1;
    int currVal = h->heap[currIndex];
    
    while (((2 * currIndex) + 1) <= h->size)
    {
        int leftChild = h->heap[currIndex * 2];
        int rightChild = h->heap[(currIndex * 2) + 1];
        
        int newIndex;
        if (currVal < MAX(leftChild, rightChild))
        {
            if (leftChild > rightChild)
            {
                newIndex = currIndex * 2;
            }
            else
            {
                newIndex = (currIndex * 2) + 1;
            }
            
            array_swap(h->heap, currIndex, newIndex);
            currIndex = newIndex;
        }
        else
        {
            break;
        }
    }
}

/*return the root (max of heap) and replace it with next max in heap
 */
int maxheap_deleteMax(maxheap_t* h)
{
    if (h->size == 0)
    {
        printf("heap empty\n");
        return 0;
    }
    
    int max = h->heap[1];
    array_swap(h->heap, 1, h->size);
    
    (h->size)--;
    maxheap_sink(h);
    
    return max;
}

/*print heap in order
 */
void maxheap_print(maxheap_t* h)
{
    for (int i = 1; i <= h->size; i++)
    {
        printf("%d ", h->heap[i]);
    }
    printf("\n");
}
















