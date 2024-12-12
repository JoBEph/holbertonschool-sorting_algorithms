#include "sort.h"

/**
 *partition - organize subtable around a pivot
 *@array: array board
 *low : element most low array
 *@high: element most high array
 *Return: final position pivot
 */
int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = low;
	
	while (high > j)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
		j++;
	}
	if (array[i + 1] != array[high])
	{	
		int temp = array[i + 1];

		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 *quicksort - function that sorts an array of integers in ascending
 *@array: int value array
 *@high: element most high array
 *@low: element most low array
 *Return: void
 */
void quicksort(int *array,int high, int low, size_t size)
{
	int part;

	if (low < high)
	{
		part = partition(array,low, high, size);
		quicksort(array, low, part - 1, size);
		quicksort(array, part + 1, high, size);
	}
}

/**
 *quick_sort - function that sorts an array of integers in ascending
 *@array: int value array
 *@size: size_t
 *Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

