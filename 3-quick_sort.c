#include "sort.h"
/**
 * quick_sort - sorts array using quickSort
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
int leftSize = 0;
int *pivot = (array + size - 1), *j = array, *i = (j - 1);
if (array == NULL || size < 2)
return;

for (j = array; j <= (pivot - 1); j++)
{
if (*j <= *pivot)
{
i++;
leftSize++;
swapNums(i, j);
print_array(array, size);
}
}
swapNums(i + 1, pivot);
print_array(array, size);
if (leftSize > 1)
quick_sort(array, leftSize);
if (size - (leftSize + 1) > 1)
quick_sort(i + 2, size - (leftSize + 1));
}

/**
 * swapNums - swaps two numbers
 * @a: first number
 * @b: second number
 * Return: void
 */
void swapNums(int *a, int *b)
{
int c;
c = *a;
*a = *b;
*b = c;
}
