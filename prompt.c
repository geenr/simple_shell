#include "main.h"

/**
 * prompt - function that prints a prompt.
 * Return: Void.
 */
void prompt(void)
{
	/*isatty works with interactive mode*/
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "cisfun$$ ", 9);
	}
}
