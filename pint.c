#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d", (*stack)->n);
}
