#include "sort.h"

void subarray_merge(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void recursive_merge_sort(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * subarray_merge - Sorts a subarray of integers
 *
 * @subarr: Subarray of an array of integers to sort
 * @buff: Buffer to store the sorted subarray
 * @front: Front index of the array
 * @mid: Mddle index of the array
 * @back: The back index of the array
 */
void subarray_merge(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * recursive_merge_sort - Implements the merge sort algorithm through recursion
 *
 * @subarr: Subarray of an array of integers to sort
 * @buff: Buffer to store the sorted result
 * @front: Front index of the subarray
 * @back: Back index of the subarray
 */
void recursive_merge_sort(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		recursive_merge_sort(subarr, buff, front, mid);
		recursive_merge_sort(subarr, buff, mid, back);
		subarray_merge(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending
 *              order using the merge sort algorithm
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: Implements the top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	recursive_merge_sort(array, buff, 0, size);

	free(buff);
}
