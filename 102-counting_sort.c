#include "sort.h"

/**
 * counting_sort - sorts an array of integer using counting sort
 * @array: input array
 * @size: array size
 *
 * Return: nothing
 */
void counting_sort(int *array, size_t size)
{
	int k, x;
	int *count, *out;

	if (size < 2)
		return;
	for (k = x = 0; x < (int)size; x++)
		if (array[x] > k)
			k = array[x];
	count = malloc(sizeof(int) * (k + 1));
	if (!count)
		return;
	for (x = 0; x <= k; x++)
		count[x] = 0;
	for (x = 0; x < (int)size; x++)
		count[array[x]] += 1;
	for (x = 1; x <= k; x++)
		count[x] += count[x - 1];
	print_array(count, k + 1);
	out = malloc(sizeof(int) * size);
	if (!out)
	{
		free(count);
		return;
	}
	for (x = 0; x < (int)size; x++)
	{
		out[count[array[x]] - 1] = array[x];
		count[array[x]] -= 1;
	}
	for (x = 0; x < (int)size; x++)
		array[x] = out[x];
	free(count);
	free(out);
}
