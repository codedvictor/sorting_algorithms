#include "sort.h"

/**
 * radix_sort - sorts an array of integers using the Radix sort algo
 * @array: input array
 * @size: array size
 *
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int tmp;
	int s_digit = 10, not_sorted = 1, prev, curr;
	size_t x;

	if (!array || size < 2)
		return;

	while (not_sorted)
	{
		not_sorted = 0;
		for (x = 1; x < size; x++)
		{
			if (((array[x - 1] % (s_digit * 10)) / s_digit) > 0)
				not_sorted = 1;
			prev = (array[x - 1] % s_digit) / (s_digit / 10);
			curr = (array[x] % s_digit) / (s_digit / 10);
			if (prev > curr)
			{
				tmp = array[x];
				array[x] = array[x - 1];
				array[x - 1] = tmp;
				if ((x - 1) > 0)
					x -= 2;
			}
		}
		print_array(array, size);
		s_digit *= 10;
	}
}
