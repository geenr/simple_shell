#include "main.h"

<<<<<<< HEAD
int main(int ac, char **av, char **env)
{
	if (ac == 1)
	{
		prompt(av, env);
	}
	return (0);
=======
/**
 * main - runs a Simple Shell program.
 * @ac: Number of arguments.
 * @av: Pointer to list of arguments.
 * Return: Always 0 if success else 1.
 */

int main(int ac, char *av[])
{
	char *line, **tokens;
	int Status;

	(void)ac;

	signal(SIGINT, ctrlc);
	Status = 0;
	while (Status == 0)
	{
		prompt();

		line = lineRead();
		if (_strcmp(line, "\n") == 0)
		{
			tokens = NULL;
			free(line);
			continue;
		}
		tokens = _strtokenize(line);
		if (tokens[0] == NULL)
		{
			free(tokens);
			free(line);
			continue;
		}

		if (_strcmp(tokens[0], "exit") == 0)
		{
			exit_shelly(tokens, line);
		}
		else
		{
			Status =  exec_tor(tokens, av[0]);
		}
		free(line);
		free(tokens);
	}
	return (Status);
>>>>>>> b0cf704aca3aa07047403c4b2e60e63f923a04bf
}
