#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order using selection sort
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int swp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			swp = array[i];
			array[i] = array[min];
			array[min] = swp;
			print_array(array, size);
		}
	}
}
