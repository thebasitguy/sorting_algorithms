#include "sort.h"

void int_swap(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

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
 * hoare_partition - Orders a subset of an array of integers
 *                   according to the hoare partition scheme
 *
 * @array: Array of integers
 * @size: Size of the array
 * @left: Starting index of the subset to order
 * @right: Ending index of the subset to order
 *
 * Return: Final partition index
 *
 * Description: Uses the last element of the partition as the pivot
 * and prints the array after each swap of two elements
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			int_swap(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implements the quicksort algorithm through recursion
 *
 * @array: Array of integers to sort
 * @size: Size of the array
 * @left: Starting index of the array partition to order
 * @right: Ending index of the array partition to order
 *
 * Description: Uses the Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending
 *                    order using the quicksort algorithm
 *
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: Uses the Hoare Partition scheme and prints
 * the array after each swap of two elements
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
