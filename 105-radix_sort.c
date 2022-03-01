#include "sort.h"
/**
 * countingSort - sort the elements in the basis of significant places
 * @array: array being sorted
 * @size: size of the array
 * @place: which digit place we are on
 */
void countingSort(int *array, int size, int place)
{
	int output[1024];
	int i, count[10] = { 0 };


	for (i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
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
	int place, max, i;


	if (!array || size < 2)
		return;
	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	for (place = 1; max / place > 0; place *= 10)
	{
		countingSort(array, size, place);
		print_array(array, size);
	}
}
