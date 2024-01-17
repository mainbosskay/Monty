#include "monty.h"

/**
 * stack_rotl - Rotatng the stack to the top
 * @head: double pointer to the head
 * @sum: number of lines
 * Return: it is void
 */

void stack_rotl(stack_t **head, unsigned int sum)
{
	stack_t *tempnode = *head;
	stack_t *currenthd;
	(void)sum;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	currenthd = (*head)->next;
	currenthd->prev = NULL;
	while (tempnode->next)
	{
		tempnode = tempnode->next;
	}
	tempnode->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tempnode;
	(*head) = currenthd;
}

/**
 * stack_rotr - Rotating the stack to the bottom
 * @head: double pointer to the head
 * @sum: number of lines
 * Return: it is void
 */

void stack_rotr(stack_t **head, unsigned int sum)
{
	stack_t *copynode;
	(void)sum;

	copynode = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copynode->next)
	{
		copynode = copynode->next;
	}
	copynode->next = *head;
	copynode->prev->next = NULL;
	copynode->prev = NULL;
	(*head)->prev = copynode;
	(*head) = copynode;
}

/**
 * stack_nop - This function does nothing
 * @head: double pointer to the head
 * @sum: number of lines
 * Return: it is void
 */

void stack_nop(stack_t **head, unsigned int sum)
{
	(void)head;
	(void)sum;
}
