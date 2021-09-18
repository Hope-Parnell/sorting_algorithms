#include "sort.h"

/**
 * selection_sort - sorts an array with selection sort 
 * @array: array to be sorted
 * @size: number of items in the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, checker;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		checker = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[checker])
				checker = j;
		}
		if (checker != i)
		{
			temp = array[i];
			array[i] = array[checker];
			array[checker] = temp;
			print_array(array, size);
		}
	}
}
