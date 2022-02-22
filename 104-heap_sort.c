#include "sort.h"

/**
 * swap - swaps two values in memory
 * @a: val 1
 * @b: val 2
 * Return: void
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * heapify - heapifies a parent and two children
 * @arr: array
 * @n: value of root
 * @i: pos of root
 * @size: size of array
 * Return: void
 */
void heapify(int arr[], int n, int i, int size)
{
/* Find largest among root, left child and right child */
int largest = i;
int left = 2 * i + 1;
int right = 2 * i + 2;

if (left < n && arr[left] > arr[largest])
largest = left;

if (right < n && arr[right] > arr[largest])
largest = right;

/* Swap and continue heapifying if root is not largest */
if (largest != i)
{
swap(&arr[i], &arr[largest]);
print_array(arr, size);
heapify(arr, n, largest, size);
}
}

/**
 * heap_sort - implements heap sort with heapify
 * @array: array
 * @size: size of array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
/* Build max heap */
for (int i = size / 2 - 1; i >= 0; i--)
heapify(array, size, i, size);

/* Heap sort */
for (int i = size - 1; i >= 0; i--)
{
swap(&array[0], &array[i]);
if (i > 0)
print_array(array, size);

/* Heapify root element to get highest element at root again */
heapify(array, i, 0, size);
}
}
