#include "sort.h"

/**
 * bubble_sort - sorting data using bubble sorting
 * @array: group of data to be sorted
 * @size: data size
 *
 * Return: 0
 */

void bubble_sort(int *array, size_t size)
{
	int swp = 1, tmp;
	size_t x;

	while (swp)
	{
		swp = 0;
		for (x = 1; x < size; x++)
		{
			if (array[x - 1] > array[x])
			{
				tmp = array[x - 1];
				array[x - 1] = array[x];
				array[x] = tmp;
				swap = 1;
				print_array(array, size);
			}
		}
		size -= 1;
	}
}
