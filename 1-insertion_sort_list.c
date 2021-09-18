#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked lists using insertion
 * @list: the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *swap;

	if (!*list || ((!(*list)->prev) && (!((*list)->next))))
		return;
	current = (*list)->next;
	while (current)
	{
		if (current->n < current->prev->n)
		{
			swap = current;
			while (swap->prev && swap->n < swap->prev->n)
			{
				prev = swap->prev;
				prev->next = swap->next;
				if (prev->prev)
					prev->prev->next = swap;
				if (swap->next)
					swap->next->prev = prev;
				swap->prev = prev->prev;
				swap->next = prev;
				prev->prev = swap;
				if (swap->prev == NULL)
					(*list) = swap;
				print_list(*list);
			}
		}
		current = current->next;
	}
}
