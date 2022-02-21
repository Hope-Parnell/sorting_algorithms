#include "sort.h"

/**
 * downsift - the downsift method for heap sort
 * @array: the array being heaped
 * @start: starting index for array
 * @stop: where to stop in the array
 * @size: length of array for printing
 * Return: void no return
 */

void downsift(int *array, int start, int stop, size_t size)
{
	int m = stop;
	int left = 2 * stop + 1;
	int right = 2 * stop + 2;
	int temp;

	if (left < start && array[left] > array[m])
		m = left;
	if (right < start && array[right] > array[m])
		m = right;

	if (m != stop)
	{
		temp = array[stop];
		array[stop] = array[m];
		array[m] = temp;
		print_array(array, size);
		downsift(array, start, m, size);
	}
}

/**
 * heap_sort - performs the heap sort on an array
 * @array: The array being heap sorted
 * @size: the size of the array
 * Return: void, no return
 */

void heap_sort(int *array, size_t size)
{
	int i, temp, s = size;

	if (!array || size < 2)
		return;
	/*Create the heap*/
	for (i = (s - 2) / 2; i >= 0; i--)
		downsift(array, s, i, size);
	/*Perform sort*/
	for (i = (s - 1); i >= 0; i--)
	{
		/*swap first and current values*/
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i != 0) /*Items were swapped*/
			print_array(array, size);
		/*reheap*/
		downsift(array, i, 0, size);
	}
}
