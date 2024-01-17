#include "monty.h"
projct_t projct = {NULL, NULL, NULL, 0};

/**
 * main - Point of entry for monty code interpreter
 * @argc: argument count
 * @argv: argument array
 * Return: it should be 0 on success
 */

int main(int argc, char *argv[])
{
	char *linecnt;
	FILE *flpntr;
	size_t linesize = 0;
	ssize_t rdres = 1;
	stack_t *stk = NULL;
	unsigned int total = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	flpntr = fopen(argv[1], "r");
	projct.flpntr = flpntr;
	if (flpntr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (rdres > 0)
	{
		linecnt = NULL;
		rdres = getline(&linecnt, &linesize, flpntr);
		projct.linecnt = linecnt;
		total++;
		if (rdres > 0)
		{
			sq_execute(linecnt, &stk, total, flpntr);
		}
		free(linecnt);
	}
	free_stack(stk);
	fclose(flpntr);
return (0);
}
