#include "monty.h"

/**
 * stack_push - Adding a new node to stack
 * @head: double pointer to the head
 * @num: number of lines
 * Return: it is void
 */

void stack_push(stack_t **head, unsigned int num)
{
	int k;
	int t = 0;
	int flag = 0;

	if (projct.argva != NULL)
	{
		if (projct.argva[0] == '-')
			t++;
		for (; projct.argva[t] != '\0' ; t++)
		{
			if (projct.argva[t] > 57 || projct.argva[t] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", num);
			fclose(projct.flpntr);
			free(projct.linecnt);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", num);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	k = atoi(projct.argva);
	if (projct.flgs == 0)
		queue_addnode(head, k);
	else
		queue_addqueue(head, k);
}

/**
 * stack_pop - Removing top element of the stack
 * @head: double pointer to the head
 * @sum: number of lines
 * Return: it is void
 */

void stack_pop(stack_t **head, unsigned int sum)
{
	stack_t *currenthd;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", sum);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	currenthd = *head;
	*head = currenthd->next;
	free(currenthd);
}

/**
 * stack_swap - Swapping the top two elements of stack
 * @head: double pointer to the head
 * @sum: number of lines
 * Return: it is void
 */

void stack_swap(stack_t **head, unsigned int sum)
{
	stack_t *currenthd;
	int length = 0;
	int temp;

	currenthd = *head;
	while (currenthd != NULL)
	{
		currenthd = currenthd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", sum);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	currenthd = *head;
	temp = currenthd->n;
	currenthd->n = currenthd->next->n;
	currenthd->next->n = temp;
}

/**
 * stack_pint - Printing the value at the top of the stack
 * @head: double pointer to the head
 * @position: number of lines
 * Return: it is void
 */

void stack_pint(stack_t **head, unsigned int position)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", position);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
