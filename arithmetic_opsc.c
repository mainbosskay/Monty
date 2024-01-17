#include "monty.h"

/**
 * stack_add - Adding the values of the top two elements of the stack
 * @head: double pointer to the head
 * @sum: number of lines
 * Return: it is void
 */

void stack_add(stack_t **head, unsigned int sum)
{
	stack_t *currenthd;
	int length = 0;
	int total;

	currenthd = *head;
	while (currenthd != NULL)
	{
		currenthd = currenthd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", sum);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	currenthd = *head;
	total = currenthd->n + currenthd->next->n;
	currenthd->next->n = total;
	*head = currenthd->next;
	free(currenthd);
}

/**
 * stack_sub - Subtracting top element from the second element of stack
 * @head: double pointer to the head
 * @sum: number of lines
 * Return: it is void
 */

void stack_sub(stack_t **head, unsigned int sum)
{
	stack_t *currenthd;
	int result;
	int count;

	currenthd = *head;
	for (count = 0 ; currenthd != NULL ; count++)
		currenthd = currenthd->next;
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", sum);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	currenthd = *head;
	result = currenthd->next->n - currenthd->n;
	currenthd->next->n = result;
	*head = currenthd->next;
	free(currenthd);
}

/**
 * stack_mul - Multipling the top two elements of the stack
 * @head: double pointer to the head
 * @sum: number of lines
 * Return: it is void
 */

void stack_mul(stack_t **head, unsigned int sum)
{
	stack_t *currenthd;
	int length = 0;
	int product;

	currenthd = *head;
	while (currenthd != NULL)
	{
		currenthd = currenthd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", sum);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	currenthd = *head;
	product = currenthd->next->n * currenthd->n;
	currenthd->next->n = product;
	*head = currenthd->next;
	free(currenthd);
}

/**
 * stack_div - Dividing the second element by the top element of the stack
 * @head: double pointer to the head
 * @sum: number of lines
 * Return: it is void
 */

void stack_div(stack_t **head, unsigned int sum)
{
	stack_t *currenthd;
	int length = 0;
	int result;

	currenthd = *head;
	while (currenthd != NULL)
	{
		currenthd = currenthd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", sum);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	currenthd = *head;
	if (currenthd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", sum);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = currenthd->next->n / currenthd->n;
	currenthd->next->n = result;
	*head = currenthd->next;
	free(currenthd);
}

/**
 * stack_mod - Computing the remainder of the division of the second
 * top element of stack by the top element of stack
 * @head: double pointer to the top of the head
 * @sum: number of lines
 * Return: it is void
 */

void stack_mod(stack_t **head, unsigned int sum)
{
	stack_t *currenthd;
	int length = 0;
	int remainder;

	currenthd = *head;
	while (currenthd != NULL)
	{
		currenthd = currenthd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", sum);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	currenthd = *head;
	if (currenthd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", sum);
		fclose(projct.flpntr);
		free(projct.linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	remainder = currenthd->next->n % currenthd->n;
	currenthd->next->n = remainder;
	*head = currenthd->next;
	free(currenthd);
}
