#include "monty.h"

/**
 * get_op_func - selects the correct function to perform the operation
 * @s: string to compare
 *
 * Return: pointer to the correct function
 */

void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
	    {"push", push},
	    {"pall", pall},
	    {"pint", pint},
	    {NULL, NULL}};
	int i;
	int g_line_number = 0;

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcodes[i].opcode, s) == 0)
			return (opcodes[i].f);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", g_line_number, s);
	exit(EXIT_FAILURE);
}
