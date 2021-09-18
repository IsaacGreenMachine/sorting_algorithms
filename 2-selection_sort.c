#include "sort.h"
/**
 * selection_sort - sorts an array using selection sort
 * @array: array
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
unsigned int innerLoop, outerLoop, posSmallest;
int smallestVal, n;
if (array == NULL || size < 2)
return;
for (outerLoop = 0; outerLoop < size; outerLoop++)
{
smallestVal = array[outerLoop];
posSmallest = outerLoop;
for (innerLoop = outerLoop; innerLoop < size; innerLoop++)
{
if (array[innerLoop] < smallestVal)
{
smallestVal = array[innerLoop];
posSmallest = innerLoop;
}
}
if (outerLoop < size - 1)
{
n = array[outerLoop];
array[outerLoop] = smallestVal;
array[posSmallest] = n;
print_array(array, size);
}
}
}
