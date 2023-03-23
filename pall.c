#include "monty.h"

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while (tmp)
	{
		printf("%d", tmp->n);
		tmp = tmp->next;
	}
}
