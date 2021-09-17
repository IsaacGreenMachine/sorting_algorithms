#include "sort.h"
/**
 * bubble_sort - sorts an array using bubble sort
 *
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
unsigned int a, i;
int c;
if (size < 2)
return;
if (array == NULL)
return;

for (i = 1; i <= size; i++)
{
for (a = 0; a < size - i; a++)
{
if (array[a] > array[a + 1])
{
c = array[a];
array[a] = array[a + 1];
array[a + 1] = c;
print_array(array, size);
}
}
}
}
