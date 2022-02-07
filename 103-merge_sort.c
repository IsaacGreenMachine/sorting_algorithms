#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
 * printThatArray - prints a slice of an array
 * @start: start printing here
 * @end: stop printing here
 * @array: array to print
 * Return: Always void
 */
void printThatArray(int start, int end, int *array)
{
int i = start;
for (int i; i < end; i++)
{
printf("%i", array[i]);
if (i < end - 1)
printf(", ");
else
printf("\n");
}
}


/**
 * CopyArray - copies array from one to another
 * @A: array to be copied from
 * @iBegin: beginning of array
 * @iEnd: end of array
 * @B: array to be copied to
 * Return: Always void
 */
void CopyArray(int A[], int iBegin, int iEnd, int B[])
{
int k = iBegin;
for (; k < iEnd; k++)
B[k] = A[k];
}

/*
 * Left source half is A[ iBegin:iMiddle-1].
 * Right source half is A[iMiddle:iEnd-1   ].
 * Result is            B[ iBegin:iEnd-1   ].
 */
/**
 * TopDownMerge - copies array from one to another
 * @A: array to be copied from
 * @iBegin: beginning of array
 * @iMiddle: desc
 * @iEnd: end of array
 * @B: array to be copied to
 * Return: Always void
 */
void TopDownMerge(int A[], int iBegin, int iMiddle, int iEnd, int B[])
{
int i = iBegin, j = iMiddle;
/* While there are elements in the left or right runs... */
int k = iBegin;
for (; k < iEnd; k++)
{
/* If left run head exists and is <= existing right run head. */
if (i < iMiddle && (j >= iEnd || A[i] <= A[j]))
{
B[k] = A[i];
i = i + 1;
}
else
{
B[k] = A[j];
j = j + 1;
}
}
printf("Merging...\n");
printf(" [left]: ");
printThatArray(iBegin, iMiddle, A);
printf(" [right]: ");
printThatArray(iMiddle, iEnd, A);
printf(" [Done]: ");
printThatArray(iBegin, iEnd, B);
}

/*
 * Split A[] into 2 runs, sort both runs into B[],
 * merge both runs from B[] to A[]
 * iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
 */
/**
 * TopDownSplitMerge - splits arrays using pointers and calls sorter function
 * @B: dummy array
 * @iBegin: beginning of array
 * @iEnd: end of array
 * @A: array with data
 * Return: Always void
 */
void TopDownSplitMerge(int B[], int iBegin, int iEnd, int A[])
{
int iMiddle;
if (iEnd - iBegin <= 1)                     /* if run size == 1 */
return;                                 /*   consider it sorted */
/* split the run longer than 1 item into halves */
iMiddle = (iEnd + iBegin) / 2;              /* iMiddle = mid point */
/* recursively sort both runs from array A[] into B[] */
TopDownSplitMerge(A, iBegin,  iMiddle, B);  /* sort the left run */
TopDownSplitMerge(A, iMiddle,    iEnd, B);  /* sort the right run */
/* merge the resulting runs from array B[] into A[] */
TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

/* Array A[] has the items to sort; array B[] is a work array. */
/**
 * merge_sort - final function for merge_sort
 * @array: array to be sorted
 * @size: size of array
 * Return: Always void
 */
void merge_sort(int *array, size_t size)
{
int dummy[1024];
CopyArray(array, 0, size, dummy);           /* one time copy of A[] to B[] */
TopDownSplitMerge(dummy, 0, size, array);   /* sort data from B[] into A[] */
}
