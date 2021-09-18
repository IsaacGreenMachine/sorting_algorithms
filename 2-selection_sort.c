#include "sort.h"
/**
 * selection_sort - sorts an array using selection sort
 * @array: array
 * @size: size of array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
unsigned int outerLoop, innerLoop, minPos;

for (outerLoop = 0; outerLoop < size - 1; outerLoop++)
{
minPos = outerLoop;
for (innerLoop = outerLoop + 1; innerLoop < size; innerLoop++)
{
if (array[innerLoop] < array[minPos])
minPos = innerLoop;
}
if (minPos != outerLoop)
{
swapNums(&array[minPos], &array[outerLoop]);
print_array(array, size);
}
}
}

/**
 * swapNums - swaps two numbers
 * @a: num 1
 * @b: num 2
 * Return: void
 */

void swapNums(int *a, int *b)
{
int swap = *a;
*a = *b;
*b = swap;
}
