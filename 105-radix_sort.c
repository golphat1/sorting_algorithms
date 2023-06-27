#include "sort.h"
#include <stdio.h>

/**
* getMax - A utility function which gets maximum value in arr[]
* @arr: array
* @n: size of the array
* Return: array
*/
int getMax(int *arr, int n)
{
	int x, max = arr[0];

	for (x = 1; x < n; x++)
		if (arr[x] > max)
			max = arr[x];
	return (max);
}

/**
* countSort - A function that do counting sort of arr[] according to
* the digit represented by exp.
* @arr: array
* @n: size of the array
* @exp: exp is 10^x
* @output: array to save the temporary values
*/
void countSort(int *arr, size_t n, int exp, int *output)
{
	int x;
	int count[10] = {0};

	/* Store count of occurrences in count[] */
	for (x = 0; x < (int)n; x++)
		count[(arr[i] / exp) % 10]++;

	/*
	* Change count[i] so that count[i] now contains actual
    * position of this digit in output[]
	*/
	for (x = 1; x < 10; x++)
		count[x] += count[x - 1];

	/* Build the output array */
	for (x = n - 1; x >= 0; x--)
	{
		output[count[(arr[x] / exp) % 10] - 1] = arr[x];
		count[(arr[x] / exp) % 10]--;
	}

	/*
	* Copy the output array to arr[], so that arr[] now
    * contains sorted numbers according to current digit
	*/
	for (i = 0; x < (int)n; x++)
		arr[x] = output[x];
	/*print_array(arr, n);*/
}

/**
* radix_sort - The main function to that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	/* Find the maximum number to know number of digits */
	int exp, maximum = 0;
	int *output = '\0'; /* output array should be n(size) */

	if (array == '\0' || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == '\0')
		return;
	/*
	* Do counting sort for every digit. Note that instead
    * of passing digit number, exp is passed. exp is 10^i
    * where i is current digit number
	*/
	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
