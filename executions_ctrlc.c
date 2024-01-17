#include "monty.h"

/**
 * sq_execute - Executing the monty bytecode instructions
 * @linecnt: line content from the monty file
 * @head: double pointer to the head
 * @sum: line counter
 * @flpntr: pointer to the monty file
 * Return: either 0 on code success or 1 otherwise
 */
int sq_execute(char *linecnt, stack_t **head, unsigned int sum, FILE *flpntr)
{
	instruction_t opcds[] = {
				{"push", stack_push}, {"pall", stack_pall},
				{"pint", stack_pint}, {"pop", stack_pop},
				{"swap", stack_swap}, {"add", stack_add},
				{"nop", stack_nop}, {"sub", stack_sub},
				{"div", stack_div}, {"mul", stack_mul},
				{"mod", stack_mod},
				{"pchar", stack_pchar},
				{"pstr", stack_pstr},
				{"rotl", stack_rotl},
				{"rotr", stack_rotr},
				{"queue", queue_queue},
				{"stack", stack_p},
				{NULL, NULL}
	};
	unsigned int k = 0;
	char *currentopcd;

	currentopcd = strtok(linecnt, " \n\t");
	if (currentopcd && currentopcd[0] == '#')
		return (0);
	projct.argva = strtok(NULL, " \n\t");
	while (opcds[k].opcode && currentopcd)
	{
		if (strcmp(currentopcd, opcds[k].opcode) == 0)
		{
			opcds[k].f(head, sum);
			return (0);
		}
		k++;
	}
	if (currentopcd && opcds[k].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", sum, currentopcd);
		fclose(flpntr);
		free(linecnt);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
