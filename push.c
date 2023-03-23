#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n;
	global_t global;

	if (global.n == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(global.n);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
