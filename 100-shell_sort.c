#include "sort.h"

/**
 * shell_sort - sorts an array in ascending order using shell sort
 * @array: array data
 * @size: array size
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t n, gp, i, j;
	int swp;

	n = 1;
	while (n < size)
		n = (n * 3) + 1;
	for (gp = (n - 1) / 3; gp > 0; gp = (gp - 1) / 3)
	{
		for (i = gp; i < size; i++)
		{
			for (j = i; j >= gp; j -= gp)
			{
				if (array[j] < array[j - gp])
				{
					swp = array[j];
					array[j] = array[j - gp];
					array[j - gp] = swp;
				}
			}
		}
		print_array(array, size);
	}
}
