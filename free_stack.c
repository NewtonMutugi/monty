#include "monty.h"

/**
 * free_stack - frees a stack_t stack
 * @stack: pointer to the head of a stack_t
 *
 * Return: void
 */

void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		return;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
