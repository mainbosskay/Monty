#include "monty.h"

/**
 * queue_addnode - Adding a new node to the head of the stack
 * @head: double pointer to the head
 * @num: new value
 * Return: it is void
 */

void queue_addnode(stack_t **head, int num)
{
	stack_t *newnode;
	stack_t *currenthd;

	currenthd = *head;
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		printf("Error\n");
		exit(0);
	}
	if (currenthd != NULL)
		currenthd->prev = newnode;
	newnode->n = num;
	newnode->next = *head;
	newnode->prev = NULL;
	*head = newnode;
}

/**
 * queue_addqueue - Adding a new node to the tail of the stack
 * @head: double pointer to the head
 * @num: new value
 * Return: it is void
 */

void queue_addqueue(stack_t **head, int num)
{
	stack_t *newnode;
	stack_t *currenthd;

	currenthd = *head;
	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		printf("Error\n");
	}
	newnode->n = num;
	newnode->next = NULL;
	if (currenthd != NULL)
	{
		while (currenthd->next)
			currenthd = currenthd->next;
	}
	if (currenthd == NULL)
	{
		*head = newnode;
		newnode->prev = NULL;
	}
	else
	{
		currenthd->next = newnode;
		newnode->prev = currenthd;
	}
}

/**
 * queue_queue - Setting the stack mode to queue using FIFO mode
 * @head: double pointer to the hea
 * @sum: number of lines
 * Return: it is void
 */

void queue_queue(stack_t **head, unsigned int sum)
{
	(void)head;
	(void)sum;
	projct.flgs = 1;
}
