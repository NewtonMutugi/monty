#include "monty.h"

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current working line number of the Monty file.
 * Description: If the stack is empty, exit with status EXIT_FAILURE.
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
