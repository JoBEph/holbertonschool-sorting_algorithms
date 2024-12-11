#include "sort.h"
/**
 *insertion_sort_list - function that sorts an array of integers in ascending
 *@list: double pointer struct
 *Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *buff, *current, *prev;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = (*list)->next;
	while (current)
	{
		buff = current;
		prev = current->prev;
		while (prev && prev->n > current->n)
		{
			if (prev->prev)
			{
				prev->prev->next = buff;
				buff->prev = prev->prev;
			}
			else
			{
				buff->prev = NULL;
				*list = buff;
			}
			if (buff->next)
			{
				prev->next = buff->next;
				prev->next->prev = prev;
			}
			else
				prev->next = NULL;
			prev->prev = buff;
			buff->next = prev;
			print_list(*list);
			prev = buff->prev;
		}
		current = current->next;
	}
}
