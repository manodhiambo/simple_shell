#include "shell.h"
/**
 * num_builtins - holds the builtin strings
 * Return: the size of the string.
 */
int num_builtins(void)
{
char *builtin_str[] = {"cd", "exit"};
return (sizeof(builtin_str) / sizeof(char *));
}
/**
 * shell_cd - builtin command to change directory
 * @args: list of arguments
 * Return: Always 1
 */
int shell_cd(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "./shell: expected argument to \"cd\"\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("./shell");
}
}
return (1);
}
/**
 * shell_exit - runs builtin command exit
 * @args: list of arguments. Not considered
 * Return: Always 0
 */
int shell_exit(char **args)
{
args = args;
return (0);
}
/**
 * launch - starts a program
 * @args: null terminated list of arguments
 * Return: Always 1
 */
int launch(char **args)
{
pid_t pid;
int status;
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("./shell");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("./shell");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}
/**
 * execute - executes builtins
 * @args: null terminated list of arguments
 * Return: returns 1 if shell continues and 0 if to terminate
 */
int execute(char **args)
{
char *builtin_str[] = {"cd", "exit"};
int (*builtin_func[])(char **) = {&shell_cd, &shell_exit};
int i;
if (args[0] == NULL)
{
return (1);
}
for (i = 0; i < num_builtins(); i++)
{
if (strcmp(args[0], builtin_str[i]) == 0)
{
return ((*builtin_func[i])(args));
}
}
return (launch(args));
}
