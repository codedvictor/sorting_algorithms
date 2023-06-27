#include "sort.h"

int lomuto_partition_scheme(int *a, int start, int end, size_t size);
void _q_sort(int *a, int start, int end, size_t size);

/**
 * quick_sort - sorts array of integer using Quick sort algo
 * @array: input array
 * @size: array size
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	_q_sort(array, 0, size - 1, size);
}

/**
 * lomuto_partition_scheme - divides array into 2 partitions
 * @a: input array
 * @start: start index
 * @end: end index
 * @size: array size
 *
 * Return: the pivot index
 */
int lomuto_partition_scheme(int *a, int start, int end, size_t size)
{
	int pivot = a[end], swp;
	int i, j;

	i = start;
	for (j = start; j < end; j++)
	{
		if (a[j] <= pivot)
		{
			if (j != i)
			{
				swp = a[i];
				a[i] = a[j];
				a[j] = swp;
				print_array(a, size);
			}
			i++;
		}
	}

	if (i != end && a[i] != pivot)
	{
		swp = a[i];
		a[i] = a[end];
		a[end] = swp;
		print_array(a, size);
	}
	return (i);
}

/**
 * _qsort - recursive quicksort algo
 * @a: input array
 * @start: start index
 * @end: end index
 * @size: array size
 *
 * Return: nothing
 */
void _qsort(int *a, int start, int end, size_t size)
{
	int p;

	if (start >= end)
		return;
	p = lomuto_partition_scheme(a, start, end, size);

	_qsort(a, start, p - 1, size);
	_qsort(a, p + 1, end, size);
}
