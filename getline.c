#include "monty.h"

/**
 * get_line - gets a line from stdin
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 * Return: void
 */

void get_line(stack_t **stack, unsigned int line_number)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
}
