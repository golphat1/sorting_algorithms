#include "sort.h"
#include <stdio.h>

/**
  * bubble_sort - Function for bubble sorting.
  * @array: Array to sort.
  * @size: Length of array.
  * Return: Nothing.
  */
void bubble_sort(int *array, size_t size)
{
	size_t x = 0, j = 0;
	int aux = 0;

	if (array == NULL || size == 0)
		return;
	for (; x < size - 1; x++)
	{
		for (j = 0; j < size - x - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j + 1];
				array[j + 1] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
}
