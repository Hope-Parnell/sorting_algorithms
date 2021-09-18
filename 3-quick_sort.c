#include "sort.h"

/**
 * separate - runs the sort
 * @array: the array being sorted
 * @size: number of items in the array
 * @high: highest portion of the array
 * @low: lowest portion of the array
 *
 * Return: place to separate the array
 */

int separate(int *array, size_t size, int high, int low)
{
	int temp, pivot = array[high], i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (j != i)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		temp = array[high];
		array[high] = array[i + 1];
		array[i + 1] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quickSort - the real quick sort
 * @array: the array being sorted
 * @size: number of items in the array
 * @high: highest portion of the array
 * @low: lowest portion of the array
 */

void quickSort(int *array, size_t size, int high, int low)
{
	int sep;

	if (low < high)
	{
		sep = separate(array, size, high, low);
		quickSort(array, size, sep - 1, low);
		quickSort(array, size, high, sep + 1);
	}
}

/**
 * quick_sort - sort an array using quick sort
 * @array: array to be sorted
 * @size: number of items in the array
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort(array, size, (int)size - 1, 0);
}
