#include "sort.h"
#include <stdlib.h>
/**
  * shell_sort - A function which sorts an array usin shell algorithm.
  * @array: array to sort.
  * @size: length of the array.
  * Return: Nothing.
  */
void shell_sort(int *array, size_t size)
{
	unsigned int x = 0, j = 0, gap = 0;
	int aux = 0;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (x = gap; x < size; x++)
		{
			aux = array[x];
			for (j = x; j >= gap && array[j - gap] > aux;
					j -= gap)
			{
				if (array[j] != array[j - gap])
					array[j] = array[j - gap];
			}
			if (array[j] != aux)
				array[j] = aux;

		}
		print_array(array, size);
	}
}
