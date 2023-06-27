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
	size_t i;
	size_t n = size;

	while (swp)
	{
		swp = 0;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				swp = 1;
				print_array(array, size);
			}
		}
		n--;
	}
}
