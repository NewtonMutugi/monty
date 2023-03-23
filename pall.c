#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the
 * top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp)
	{
		printf("%d, ", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
