#include "sort.h"

void node_swap_front(listint_t **list, listint_t **tail, listint_t **shaker);
void node_swap_back(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * node_swap_front - Swaps a node in a listint_t doubly-linked list
 *			list of integers with the node ahead of it
 *
 * @list: Pointer to the head of a doubly-linked list of integers
 * @tail: Pointer to the tail of the doubly-linked list
 * @shaker: Pointer to the current swapping node of the cocktail shaker algorithm
 */
void node_swap_front(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * node_swap_back - Swaps a node in a listint_t doubly-linked
 *			list of integers with the node behind it
 *
 * @list: Pointer to the head of a doubly-linked list of integers
 * @tail: Pointer to the tail of the doubly-linked list
 * @shaker: Pointer to the current swapping node of the cocktail shaker algorithm
 */
void node_swap_back(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sorts a listint_t doubly-linked list of integers in
 *			ascending order using the cocktail shaker algorithm
 * @list: Pointer to the head of a listint_t doubly-linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				node_swap_front(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				node_swap_back(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
