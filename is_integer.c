#include "monty.h"

/**
 * is_integer - checks if a string is an integer
 * @str: string to check
 *
 * Return: 1 if true, 0 if false
 */

int is_integer(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);

    if (str[0] == '-')
        i = 1;

    for (; str[i] != '\0'; i++)
    {
        if (isdigit(str[i]) == 0)
            return (0);
    }

    return (1);
}
