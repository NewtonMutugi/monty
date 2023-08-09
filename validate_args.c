#include "monty.h"

/**
 * validate_args - Validates the command line arguments.
 * @argc: The number of command line arguments (should be 2)
 * @argv: An array of strings containing the command line arguments
 *
 * Return: 1 if successful, otherwise 0
 */

int validate_args(int argc, char *argv[])
{
	(void)argv;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (0);
	}
	return (1);
}
