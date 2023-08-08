#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */

char *g_buffer = NULL;
header_t header;

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int i = 0;

	if (g_buffer == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (g_buffer[0] == '-')
		i++;
	while (g_buffer[i])
	{
		if (g_buffer[i] < '0' || g_buffer[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(g_buffer);
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
}
