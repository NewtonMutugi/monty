#include "monty.h"

/**
 * main - Entry point
 * @argc: The number of command line arguments (should be 2)
 * @argv: An array of strings containing the command line arguments
 *
 * Return: EXIT_SUCCESS if successful, otherwise EXIT_FAILURE
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *file = fopen(argv[1], "r");
	char buffer[1024];
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
	};
	size_t i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), file))
	{
		char *opcode = strtok(buffer, " \t\n");

		if (!opcode || opcode[0] == '#')
			continue;

		for (i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, 0);
				break;
			}
		}
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
