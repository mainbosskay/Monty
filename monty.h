#ifndef STKQS_HEADER
#define STKQS_HEADER

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>

/**
 * struct projct_s - Program data storage structure
 * @argva: arguments value
 * @flpntr: pointer to associated file
 * @linecnt: pointer to line contents
 * @flgs: flags in which mode-switch between stack and queue is
 */

typedef struct projct_s
{
	char *argva;
	FILE *flpntr;
	char *linecnt;
	int flgs;
} projct_t;
extern projct_t projct;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* basic_stack_ops.c */
void stack_push(stack_t **head, unsigned int num);
void stack_pop(stack_t **head, unsigned int sum);
void stack_swap(stack_t **head, unsigned int sum);
void stack_pint(stack_t **head, unsigned int position);

/* print_display_ops.c */
void stack_pall(stack_t **head, unsigned int num);
void stack_pchar(stack_t **head, unsigned int position);
void stack_pstr(stack_t **head, unsigned int position);
void stack_p(stack_t **head, unsigned int sum);

/* arithmetic_ops.c */
void stack_add(stack_t **head, unsigned int sum);
void stack_sub(stack_t **head, unsigned int sum);
void stack_mul(stack_t **head, unsigned int sum);
void stack_div(stack_t **head, unsigned int sum);
void stack_mod(stack_t **head, unsigned int sum);

/* rotation_misc.c */
void stack_rotl(stack_t **head, unsigned int sum);
void stack_rotr(stack_t **head, unsigned int sum);
void stack_nop(stack_t **head, unsigned int sum);

/* queue.operations.c */
void queue_addnode(stack_t **head, int num);
void queue_addqueue(stack_t **head, int num);
void queue_queue(stack_t **head, unsigned int sum);

/* mem_management.c */
void free_stack(stack_t *head);

/* execution_ctrl.c */
int sq_execute(char *linecnt, stack_t **head, unsigned int sum, FILE *flpntr);

#endif
