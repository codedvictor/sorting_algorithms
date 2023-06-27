#include "sort.h"

/**
 * insertion_sort_list - sorts  doubly linked list
 * @list: pointer to the head of the list
 *
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *potr, *curt, *left_top;

	if (!list || !*list || !(*list)->next)
		return;
	potr = (*list)->next;
	while (potr)
	{
		left_top = potr;
		while (left_top->prev && (left_top->prev)->n > left_top->n)
		{
			curt = left_top->prev;
			curt->next = left_top->next;
			left_top->prev = curt->prev;

			if (curt->prev)
				(curt->prev)->next = left_top;
			if (left_top->next)
				(left_top->next)->prev = curt;

			left_top->next = curt;
			curt->prev = left_top;

			if (!left_top->prev)
				*list = left_top;

			print_list(*list);

		}
		potr = potr->next;
	}
}
