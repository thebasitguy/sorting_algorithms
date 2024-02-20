#include "sort.h"

void int_swap(int *a, int *b);
void btree_bheap(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

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
 * btree_bheap - Turns a binary tree into a complete binary heap
 *
 * @array: Array of integers representing a binary tree
 * @size: Size of the array or tree
 * @base: Index of the base row of the tree
 * @root: Root node of the binary tree
 */
void btree_bheap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		int_swap(array + root, array + large);
		print_array(array, size);
		btree_bheap(array, size, base, large);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm
 *
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: Implements the sift-down heap sort
 *				algorithm and prints the array after each swap
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		btree_bheap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		int_swap(array, array + i);
		print_array(array, size);
		btree_bheap(array, size, i, 0);
	}
}
