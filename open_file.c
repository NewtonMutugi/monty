#include "monty.h"

/**
 * open_file - Opens the input file.
 * @filename: The name of the file to open
 *
 * Return: A pointer to the opened file, or NULL on failure
 */

FILE *open_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
	}
	return (file);
}