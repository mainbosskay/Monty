#include "monty.h"

/**
 * free_stack - Frees all nodes in doubly linked list
 * @head: pointer to the head
 * Return: it is void
 */

void free_stack(stack_t *head)
{
	stack_t *currenthd;

	currenthd = head;
	while (head != NULL)
	{
		currenthd = head->next;
		free(head);
		head = currenthd;
	}
}
