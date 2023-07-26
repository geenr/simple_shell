#include "main.h"

/**
  *_printenv - function that Prints variables in current
  * working environment.
  * Return: void.
  */
void _printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		i++;
	}
}

/**
 * built_in - function that Checks if token is a built in.
 * @str: Pointer to string to check.
 * Return: 0 if true else 1.
 */
int built_in(char *str)
{
	if ((_strcmp(str, "env")) == 0)
	{
		return (0);
	}
	if ((_strcmp(str, "exit")) == 0)
		return (0);
	if ((_strcmp(str, "setenv")) == 0)
		return (0);
	if ((_strcmp(str, "unsetenv")) == 0)
		return (0);
	return (1);

}

/**
 * builtin_exec - function that executes a builtin Function.
 * @tokens: Double pointer to tokens.
 * Return: 0 if success.
 */
int builtin_exec(char **tokens)
{
	if ((_strcmp(*tokens, "env")) == 0)
	{
		_printenv();
		return (0);
	}
	if ((_strcmp(*tokens, "setenv")) == 0)
	{
		if (tokens[1] && tokens[2])
		{
			create_env(tokens[1], tokens[2]);
			return (0);
		}
		/*else print a ERR message*/
		printf("Usage: setenv var_name var_value\n");
		return (0);
	}
	if (_strcmp(*tokens, "unsetenv") == 0)
	{
		if (tokens[1])
		{
			_unsetenv(tokens[1]);
			return (0);
		}
		/*else an error msg*/
		printf("Usage: unsetenv VAR_NAME\n");
		return (0);
	}

	return (1);
}
/**
 * exit_shelly -function that Exits the shell
 * and frees memory.
 * @tokens: Double pointer to words split from line.
 * @line: Pointer to string got using getLine().
 * Return: void.
 */
void exit_shelly(char **tokens, char *line)
{
	int status;

	if (tokens[1] != NULL)
	{
		status = atoi(tokens[1]);
		if (status >= 0)
		{
			free(line);
			free(tokens);
			exit(status);
		}
		write(STDERR_FILENO, "Exit: illegal exit status: ", 28);
		write(STDERR_FILENO, tokens[1], 1);
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		free(line);
		free(tokens);
		exit(0);
	}
}
