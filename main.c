#include "monty.h"

/* Global variable to hold the stack */
stack_t *stack = NULL;

/* Main function to interpret Monty bytecode */
int main(int argc, char *argv[])
{
	/* Check for correct number of arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}

	/* Open the bytecode file */
	FILE *file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	/* Read and interpret the bytecode commands */
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), file))
	{
		/* Tokenize the buffer and identify the opcode */
		char *opcode = strtok(buffer, " \t\n");
		if (!opcode || opcode[0] == '#')
			continue;

		/* Call the corresponding function based on the opcode */
		instruction_t instructions[] = {
		    {"push", push},
		    {"pall", pall},
		    /* Add more opcode-function pairs here */
		};

		for (size_t i = 0; i < sizeof(instructions) / sizeof(instructions[0]); i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, 0); // You'll need to pass the correct line_number here
				break;
			}
		}
	}

	/* Close the file and clean up */
	fclose(file);
	return EXIT_SUCCESS;
}
