#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char *token;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		token = strtok(line, " \n\t\r");
		if (token == NULL)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, " \n\t\r");
			push(&stack, line_number);
		}
		else if (strcmp(token, "pall") == 0)
			pall(&stack, line_number);
		else if (strcmp(token, "pint") == 0)
			pint(&stack, line_number);
		else if (strcmp(token, "pop") == 0)
			pop(&stack, line_number);
		else if (strcmp(token, "swap") == 0)
			swap(&stack, line_number);
		else if (strcmp(token, "add") == 0)
			add(&stack, line_number);
		else if (strcmp(token, "nop") == 0)
			nop(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s", line_number, token);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	fclose(fp);
	return (0);
}
