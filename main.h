#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>


extern char **environ;
void _puts(char *str);
void prompt(void);
char *lineRead(void);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char **_strtokenize(char *str);
/*executor prototype*/
int exec_tor(char **tokens, char *args);
void env_print(void);
int _strcmp(char *s1, char *s2);
/*execute prototypes*/
int built_in(char *str);
int builtin_exec(char **tokens);
void exit_shelly(char **tokens, char *line);
/*our own cp,cmp,atoi prototypes*/
int our_atoi(char *s);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
void _kill(char *lineptr, char *tmp, char **tok);
/*ctrlc prototype*/
void ctrlc(int signum);
int isDelim(char c, const char *delim);
char *_strtok(char *src, const char *delim);
ssize_t get_line(char **str);
int handle_path(char **tokens);
/*file executor prototype*/
int file_status(char *s);
char *path_builder(char **tokens);
int file_exec(char **tokens, char *path, char *args);
/*creating an environment variable prototypes*/
char *varEnvBuild(char *var_name, char *var_value);
int create_env(char *var_name, char *var_value);
int _unsetenv(char *var_name);
char *_strdup(char *str);

#endif
