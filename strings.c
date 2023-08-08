#include "monty.h"

/**
 * strtok - breaks a string into a sequence of zero or more nonempty tokens
 * @str: string to be parsed
 * @delim: string containing the delimiter characters
 * Return: pointer to the first token or NULL if no tokens found
 */

char *_strtok(char *str, const char *delim)
{
	static char *next;
	char *token;

	if (str)
		next = str;

	if (!*next)
		return (NULL);

	token = next;

	next = _strpbrk(next, delim);

	if (next)
		*next++ = '\0';

	return (token);
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to be parsed
 * @accept: string containing the characters to match
 * Return: pointer to the byte in s that matches one of the bytes in accept
 * or NULL if no such byte is found
 */

char *_strpbrk(char *s, const char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
				return (s);
		}

		s++;
	}

	return (NULL);
}

/**
 * _strcmp - compares two strings
 * @s1: first string to be compared
 * @s2: second string to be compared
 * Return: difference between the two strings
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
			break;
	}

	return (s1[i] - s2[i]);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 * Return: integer value of string
 */

int _atoi(char *s)
{
	int i, sign = 1, num = 0;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + sign * (s[i] - '0');

		if (num && !(s[i] >= '0' && s[i] <= '9'))
			break;
	}

	return (num);
}

/**
 * _isdigit - checks for a digit (0 through 9)
 * @c: character to be checked
 * Return: 1 if c is a digit, otherwise 0
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _isnumber - checks for a number
 * @s: string to be checked
 * Return: 1 if s is a number, otherwise 0
 */

int _isnumber(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (!_isdigit(s[i]))
			return (0);
	}

	return (1);
}
