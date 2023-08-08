#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *opcode = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t\r");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			push(&stack, line_number);
		}
		else
		{
			get_op_func(opcode)(&stack, line_number);
		}
	}
	free(line);
	free_stack(&stack);
	fclose(file);
	return (0);
}
