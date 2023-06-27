#include "sort.h"

/**
 * selection_sort - function which use selection sort algorithm.
 * @array: array to sort.
 * @size: size of the array.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	int aux = 0;
	size_t x = 0, j = 0, pos = 0;

	if (array == NULL || size == 0)
		return;

	for (; x < size - 1; x++)
	{
		pos = x;
		for (j = x + 1; j < size; j++)
		{
			if (array[j] < array[pos])
				pos = j;
		}
		if (pos != x)
		{
			aux = array[x];
			array[x] = array[pos];
			array[pos] = aux;
			print_array(array, size);
		}
	}
}
