#include "sort.h"

/**
 *selection_sort - function that sorts an array of integers in ascending
 *@array: pointer value array
 *@size: size_t
 *Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
		print_array(array, size);
	}
}
