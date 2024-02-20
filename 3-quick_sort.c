#include "sort.h"

void int_swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * int_swap - Swap two integers in an array
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
 * lomuto_partition - Orders a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot)
 *
 * @array: Aray of integers
 * @size: Size of the array
 * @left: Starting index of the subset to order
 * @right: Ending index of the subset to order
 *
 * Return: Final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				int_swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		int_swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion
 *
 * @array: Array of integers to sort
 * @size: Size of the array
 * @left: Starting index of the array partition to order
 * @right: Ending index of the array partition to order
 *
 * Description: Uses the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm
 *
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: Uses the Lomuto partition scheme and prints
 *              the array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
