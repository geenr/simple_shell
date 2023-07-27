#include "main.h"

/**
 * _strlen - function that returns length of a string.
 * @s: Pointer to string.
 * Return: Length of s.
 */
int _strlen(char *s)
{
	int index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}
/**
 * _strcat - function that concatenates two strings.
 * @dest: Pointer to string to be conatenated upon.
 * @src: Pointer to string to append to dest.
 * Return: Pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	char *destAddress;
	int destLen;

	destAddress = dest;
	destLen = _strlen(dest);
	destAddress = destAddress + destLen;
	while (*src != '\0')
	{
		*destAddress = *src;
		src++;
		destAddress++;
	}
	*destAddress = '\0';

	return (dest);
}

/**
 * white_spacey - function that checks for white space.
 * @s: Pointer to string to check.
 * Return: integer.
 */
unsigned int white_spacey(char *s)
{
	int a, z = 0;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (s[a]  == ' ' || s[a] == '\t' || s[a] == '\n')
			z++;
	}
	return (z);
}

/**
 * _strtokenize - function that splits a string into words.
 * @str: Pointer to string.
 * Return: Pointer to array of words.
 */
char **_strtokenize(char *str)
{
	int i = 0;
	const char delim[] = " \t\n";
	int space = white_spacey(str);
	char **tokens = malloc(sizeof(char *) * (space + 1));
	char *token;

	if (!tokens)
	{
		free(tokens);
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}

	token = strtok(str, delim);

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] =  NULL;
	return (tokens);
}



/**
 * _puts - function that prints a string, followed by a new line, to stdout.
 * @str: string to print.
 */

void _puts(char *str)
{
	unsigned long i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
}
