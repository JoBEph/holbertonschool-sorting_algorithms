#include "sort.h"
#include <stdio.h>

/**
 *insertion_sort_list - function that sorts an array of integers in ascending
 *@list: double pointer struct
 *Return: Void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *buff, *current, *next, *prev;

	if (!list || !(*list)->next)
	{
		return;
	}
	current = (*list)->next;
	
	while (current)
	{
		buff = current;
		prev = current->prev;
		next = current->next;
		printf("cc %d %d\n", buff->n, prev->n);
		
		while (prev && prev->n > current->n)
		{
			next = prev;
			prev = prev->prev;
			printf("cc2 %d %d\n", buff->n, prev->n);
		}
		prev->next = buff;
		buff->next = next;
		current = current->next;
		printf("cc3\n");
		print_list(*list);
		printf("cc4\n");
	}

}
