#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack");
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(temp);
}