#include "sort.h"
/**
 * countingSort - sort the elements in the basis of significant places
 * @array: array being sorted
 * @size: size of the array
 * @place: which digit place we are on
 */
void countingSort(int *array, size_t size, int place)
{
	int output[1024], count[1024], j;
	size_t i, max = (array[0] / place) % 10;

	for (i = 1; i < size; i++)
	{
		if (((array[i] / place) % 10) > (int)max)
			max = array[i];
	}
	for (i = 0; i < max; ++i)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / place) % 10] - 1] = array[j];
		count[(array[j] / place) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}
/**
 * radix_sort - sort using radix algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	size_t place, max, i;


	if (!array || size < 2)
		return;
	for (i = 1; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}
	for (place = 1; max / place > 0; place *= 10)
	{
		countingSort(array, size, place);
		print_array(array, size);
	}
}
