#include "sort.h"
/**
 * quick_sort - implements sort
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
sort(array, size, array, size);
}

/**
 * sort - sorts array using quickSort algorithm
 * @array: array to sort
 * @size: size of array
 * @fullArray: pointer to entire array
 * @fullSize: size of entire array
 * Return: void
 */
void sort(int *array, size_t size, int *fullArray, int fullSize)
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
if (i != j)
{
swapNums(i, j);
print_array(fullArray, fullSize);
}
}
}
if (i + 1 != pivot)
{
swapNums(i + 1, pivot);
print_array(fullArray, fullSize);
}
if (leftSize > 1)
sort(array, leftSize, fullArray, fullSize);
if (size - (leftSize + 1) > 1)
sort(i + 2, size - (leftSize + 1), fullArray, fullSize);
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
