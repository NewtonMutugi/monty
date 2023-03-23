#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty");
		exit(EXIT_FAILURE);
	}
	printf("%d", (*stack)->n);
}
