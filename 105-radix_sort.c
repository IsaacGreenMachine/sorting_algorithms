#include "sort.h"
/**
 * getMax - Function to get the largest element from an array
 * @array: array to get max
 * @n: size of array
 * Return: max of array
 */
int getMax(int array[], int n)
{
int max = array[0];
int i;
for (i = 1; i < n; i++)
if (array[i] > max)
max = array[i];
return (max);
}

/**
 * countingSort - sort the elements given place value
 * @array: array to get max
 * @size: size of array
 * @place: place value to sort by
 * Return: always void
 */
void countingSort(int array[], int size, int place)
{
int max;
int *output = malloc(sizeof(int) * 8000);
int *count = malloc(sizeof(int) * 8000);
int i;
max = (array[0] / place) % 10;

for (i = 1; i < size; i++)
{
if (((array[i] / place) % 10) > max)
max = array[i];
}
for (i = 0; i < max; ++i)
count[i] = 0;

/* Calculate count of elements */
for (i = 0; i < size; i++)
count[(array[i] / place) % 10]++;

/* Calculate cumulative count */
for (i = 1; i < 10; i++)
count[i] += count[i - 1];

/* Place the elements in sorted order */
for (i = size - 1; i >= 0; i--)
{
output[count[(array[i] / place) % 10] - 1] = array[i];
count[(array[i] / place) % 10]--;
}

for (i = 0; i < size; i++)
array[i] = output[i];

free(count);
free(output);
}

/**
 * radix_sort - implements radix sort
 * @array: array to get max
 * @size: size of array
 * Return: always void
 */
void radix_sort(int *array, size_t size)
{
int place;
/* Get maximum element */
int maxval;
maxval = getMax(array, size);

/* Apply counting sort to sort elements based on place value. */
for (place = 1; maxval / place > 0; place *= 10)
{
countingSort(array, size, place);
print_array(array, size);
}
}
