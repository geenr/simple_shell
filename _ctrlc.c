#include "main.h"

/**
 *ctrlc - function that handles control C handler.
 *@signum: The signal number received.
 *
 *Return: Void.
 */
void ctrlc(int signum)
{
	(void)signum;

	write(STDOUT_FILENO, "\ncisfun$$ ", 10);
}

/**
 * isDelim - function that checks if char is equal to delim.
 * @c: character.
 * @delim: " "
 * Return: 0 if no match, 1 if matched.
 */

int isDelim(char c, const char *delim)
{
	while (delim && *delim)
	{
		if (c == *delim)
		{
			return (1);
		}
		++delim;
	}
	return (0);
}

/**
 * _strtok - function that mimics strtok, which
 * tokenizes a string and turn to array.
 * @src: String from getline.
 * @delim: " ";
 * Return: Individual token in array format.
 */

char *_strtok(char *src, const char *delim)
{
	static char *s;
	static unsigned int i;
	char *result = NULL;
	int space = 0;

	if (src)
	{
		s = src;
		for (i = 0; s[i]; i++)
		{
			if (isDelim(s[i], delim))
				s[i] = '\0';
		}
	}

	if (s == NULL || *s == '\0')
		return (NULL);
	result = s;
	i = _strlen(s);
	if (s[i] == '\0' && _strlen(s) > 0)
		space = 1;
	s = s + _strlen(s) + space;
	return (result);
}

/**
 * get_line - function that stores into malloced buffer
 * the user's command into shell.
 * @str: Buffer.
 * Return: Number of characters read.
 */
ssize_t get_line(char **str)
{
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	/* while there's stdin greater than buffsize; -1 to add a '\0' */
	while (t2 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{
		if (i == -1)
			return (-1);

		buff[i] = '\0';

		n = 0; /* last loop if \n is found in the stdin read */
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}

		if (t == 0)
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buff);
			size = i;
			t = 1;
		}
		else
		{
			size += i;
			*str = _strcat(*str, buff);
		}
	}
	return (size);
}
/**
 *  _strdup - function that duplicates string.
 *  @str: String to duplicate.
 *  Return: Pointer to duplicated string in allocated memory.
 */
char *_strdup(char *str)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;
	len++;
	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		duplicate_str[i] = str[i];
		i++;
	}
	return (duplicate_str);
}
