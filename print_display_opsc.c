#include "monty.h"

/**
 * stack_pall - Printing all elements in the stack
 * @head: double pointer to the head
 * @num: number of lines
 * Return: it is void
 */

void stack_pall(stack_t **head, unsigned int num)
{
	stack_t *currenthd;
	(void)num;

	currenthd = *head;
	if (currenthd == NULL)
		return;
	while (currenthd != NULL)
	{
		printf("%d\n", currenthd->n);
		currenthd = currenthd->next;
	}
}

/**
 * stack_pchar - Printing the character at the top of the stack
 * @head: double pointer to the head
 * @position: number of lines
 * Return: it is void
 */

void stack_pchar(stack_t **head, unsigned int position)
{
	stack_t *currenthd;

	currenthd = *head;
	if (currenthd == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", position);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (currenthd->n > 127 || currenthd->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", position);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", currenthd->n);
}

/**
 * stack_pstr - Printing the string at the top of the stack
 * @head: double pointer to the head
 * @position: number of lines
 * Return: it is void
 */

void stack_pstr(stack_t **head, unsigned int position)
{
	stack_t *currenthd;
	(void)position;

	currenthd = *head;
	while (currenthd != NULL)
	{
		if (currenthd->n > 127 || currenthd->n <= 0)
		{
			break;
		}
		printf("%c", currenthd->n);
		currenthd = currenthd->next;
	}
	printf("\n");
}

/**
 * stack_p - Printing the top stack in LIFO mode
 * @head: double pointer to the head
 * @sum: number of lines
 * Return: it is void
 */

void stack_p(stack_t **head, unsigned int sum)
{
	(void)head;
	(void)sum;
	projct.flgs = 0;
}
