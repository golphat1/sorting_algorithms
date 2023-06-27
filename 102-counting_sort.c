#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * counting_sort - A function which sorts an array using counting algorithm.
  * @array: array to sort.
  * @size: length of the array.
  * Return: Nothing.
  */
void counting_sort(int *array, size_t size)
{
	unsigned int x = 1;
	int *counter = NULL, k = 0, j = 0;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (; x < size; x++)
	{
		if (array[x] > k)
			k = array[x];
	}

	counter = malloc(sizeof(int) * (k + 1));
	if (counter == NULL)
		return;

	for (j = 0; j <= k; j++)
		counter[j] = 0;
	for (x = 0; x < size; x++)
		counter[array[i]] += 1;
	for (j = 0; j < k; j++)
	{
		counter[j + 1] += counter[j];
		printf("%d, ", counter[j]);
	}
	counter[j + 1] += counter[j];
	printf("%d\n", counter[j + 1]);
	for (i = 0; x < size; x++)
	{
		j = counter[array[x]] - 1;
		if (array[x] != array[j])
		{
			k = array[x];
			array[x] = array[j];
			array[j] = k;
		}
	}
	free(counter);
}
