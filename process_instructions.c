#include "monty.h"

/**
 * process_instructions - Process the instructions from the input file.
 * @file: The opened input file
 */
void process_instructions(FILE *file)
{
	stack_t *stack = NULL;
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

	while (fgets(buffer, sizeof(buffer), file))
	{
		char *opcode = strtok(buffer, " \t\n");

		if (!opcode || opcode[0] == '#')
		{
			continue;
		}

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
}
