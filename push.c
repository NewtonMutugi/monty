#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int i;
	char *g_buffer = NULL; /* global buffer */

	for (i = 0; g_buffer[i] != '\0'; i++)
	{
		if (g_buffer[i] == '-' && i == 0)
			continue;
		if (isdigit(g_buffer[i]) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(g_buffer);
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}

	free(g_buffer);
}
