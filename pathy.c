#include "main.h"


/**
 * file_status -function that Checks file status
 * @s: Pointer to file name.
 * Return: 0 if success, else non zero.
 */
int file_status(char *s)
{
	struct stat st;

	return (stat(s, &st));
}


/**
 * path_builder -function that builds a path to binaries.
 * @tokens: Double pointer to tokens.
 * Return: Return - path, else - NULL.
 */
char *path_builder(char **tokens)
{
	char path1[100] = "/bin/";
	char path2[100] = "/usr/bin/";

	char *finalPath1;
	char *finalPath2;

	finalPath1 = _strcat(path1, tokens[0]);

	if ((file_status(finalPath1) == 0))
		return (finalPath1);

	finalPath2 = _strcat(path2, tokens[0]);
	if ((file_status(finalPath2) == 0))
		return (finalPath2);

	return (NULL);
}

/**
 * file_exec - function that executes a file.
 * @tokens: Split string into tokens from stdin.
 * @path: Path from path_builder function.
 * @args: Program arguments.
 * Return: 0 - on success, else - 1.
 */
int file_exec(char **tokens, char *path, char *args)
{
	char *err1, *err2, *err3;
	pid_t myChild;
	int status;
	/*we are forking a child process*/
	myChild = fork();
	if (myChild == -1)
	{
		perror("Error: ");
		return (1);
	}

	if (myChild == 0)
	{
		tokens[0] = path;

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
	return (EXIT_SUCCESS);
}
