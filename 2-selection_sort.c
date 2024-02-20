#include "sort.h"

/**
 * int_swap - Swaps two integers in an array
 *
 * @a: First integer
 * @b: Second integer
 */
void int_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm
 *
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: Prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			int_swap(array + i, min);
			print_array(array, size);
		}
	}
}
