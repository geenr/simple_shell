<<<<<<< HEAD
#include "shell.h"

#define MAX_COMMAND 10
void prompt(char **av, char **env)
{
	char *string = NULL;
	int i, j,  status;
	size_t n = 0;
	ssize_t num_char;
	char *argv[MAX_COMMAND];
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("shell$ ");

		num_char = getline(&string, &n, stdin);
		if (num_char == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while(string[i])
		{
			if (string[i] == '\n')
				string[i] = 0;
			i++;
		}
		j = 0;
		argv[0] = strtok(string, " ");
		while (argv[j])
		{
			j++;
			argv[j] = strtok(NULL, " ");
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);

=======
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
>>>>>>> b0cf704aca3aa07047403c4b2e60e63f923a04bf
	}
}
