/*common utilities
 */

#include "utilities.h"

void array_swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
