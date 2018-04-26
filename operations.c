#include "monty.h"

/**
 * push_func - pushes an element to the stack
 * @stack: stack
 * @line_number: line number
 */

void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	printf("------------\n");
	printf("push func: ");
	if (stack == NULL)
		printf("stack is NULL, ");
	printf("line number SEGFAA: %d\n", line_number);
	printf("SEGHERE??");

	new = malloc(sizeof(stack_t));
	printf("SEGHERE?????");
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = global_var;
	new->prev = NULL;

	if (*stack == NULL)
	{
		new->next = NULL;
		*stack = new;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
	printf("value of n%d\n", new->n);
}
/**
 * pall_func - prints all the values on the stack, starting from the top
 * @stack - stack
 * @line_number: line number
 */

void pall_func(stack_t **stack, unsigned int line_number)
{
	printf("------------\n");
	printf("pall func: ");
	if (stack == NULL)
		printf("stack is NULL, ");
	printf("line number: %d\n", line_number);
}

/**
 * get_op - matches opcode from input to existing opcode in struct
 * @op: character to check
 * Return: the pointer to the appropriate function or NULL if nothing matches
 */

void get_func(char *op, stack_t *stack, unsigned int line_number)
{
	instruction_t find_op[] = {
		{"push", push_func},
		{"pall", pall_func},
		{NULL, NULL}
	};
	int index = 0;

	while (find_op[index].opcode != NULL)
	{
		if (strcmp(find_op[index].opcode, op) == 0)
		{
			find_op[index].f(&stack, line_number);
		}
		index++;
	}
	printf("L%d: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
