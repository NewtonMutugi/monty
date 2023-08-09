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
	FILE *file = open_file(argv[1]);

	if (!validate_args(argc, argv))
	{
		return (EXIT_FAILURE);
	}
	if (!file)
	{
		return (EXIT_FAILURE);
	}

	process_instructions(file);

	return (EXIT_SUCCESS);
}
