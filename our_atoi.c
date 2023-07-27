#include "main.h"

/**
 * _strcmp - function that compares two strings.
 * @s1: Pointer to First string.
 * @s2: Pointer to Second string.
 * Return: 0 if they are equal, Otherwise - positive value.
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0;

	while (s1[a] != '\0' || s2[a] != '\0')
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}
/**
 * our_atoi - function that custom atoi converts string to int.
 * @s: string.
 * Return: Number if success, -1 if string contains non-numbers.
 */
int our_atoi(char *s)
{
	int a = 0;
	unsigned int nmb = 0;

	while (s[a] != '\0')
	{
		if (s[a] >= '0' && s[a] <= '9') /* calculate num */
			nmb = nmb * 10 + (s[a] - '0');
		if (s[a] > '9' || s[a] < '0') /* account for non-numbers */
			return (-1);
		a++;
	}
	return (nmb);
}


/**
 * _strcpy - function that copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: Copy source to this buffer.
 * @src: This is the source to copy.
 * Return: Copy of original source.
 */

char *_strcpy(char *dest, char *src)
{
	int a, len;

	for (len = 0; src[len] != '\0'; len++)
		;

	for (a = 0; a <= len; a++)
		dest[a] = src[a];

	return (dest);
}

/**
 * _putchar - function that writes the character c to stdout.
 * almost similar to printf.
 * @c: The character to print.
 * Return: On success - 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
