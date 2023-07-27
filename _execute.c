#include "main.h"

/**
 * exec_tor -function that Executes a file.
 * @tokens: Split string into tokens from stdin.
 * @args: Program arguments.
 * Return: 0 if success. otherwise - 1.
 */
int exec_tor(char **tokens, char *args)
{
	char *err1, *err2, *err3;
	pid_t myChild;
	int status;
	char *path;

	if (built_in(*tokens) == 0)
	{
		status = builtin_exec(tokens);
		return (status);
	}

	path = path_builder(tokens);
	if (path != NULL)
	{
		status = file_exec(tokens, path, args);
		return (status);
	}
	myChild = fork();
	if (myChild == -1)
	{
		perror("Error: ");
		return (1);
	}
	if (myChild == 0)
	{

		if (execve(tokens[0], tokens, NULL) == -1)
		{
			err1 = _strcat(*tokens, ": No such file or directory\n");
			err2 = _strcat(args, ":");
			err3 = _strcat(err2, err1);
			write(STDERR_FILENO, err3, _strlen(err3));
			free(tokens);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);

	return (0);
}
