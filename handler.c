#include "shell.h"
/**
 * read_line - gets input from user and reads the line
 * Return: the user input.
 */
char *read_line(void)
{
char *line = NULL;
size_t bufsize = 0;
if (getline(&line, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
exit(EXIT_SUCCESS);
}
else
{
perror("./shell: getline\n");
exit(EXIT_FAILURE);
}
}
return (line);
}
/**
 * split_line - splits line into tokens for execution.
 * @line: stdin from user
 * Return: NULL terminated array of tokens
 */
char **split_line(char *line)
{
int bufsize = TOK_BUFSIZE, position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token, **tokens_backup;
if (!tokens)
{
fprintf(stderr, "./shell: allocation error\n");
exit(EXIT_FAILURE);
}
token = strtok(line, TOK_DELIM);
while (token != NULL)
{
tokens[position] = token;
position++;
if (position >= bufsize)
{
bufsize += TOK_BUFSIZE;
tokens_backup = tokens;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
free(tokens_backup);
fprintf(stderr, "./shell: allocation error\n");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, TOK_DELIM);
}
tokens[position] = NULL;
return (tokens);
}
/**
 * shell_loop - prints looped prompt and waits for user to enter input
 */
void shell_loop(void)
{
char *line;
char **args;
int status;
do {
printf("cisfun>> ");
line = read_line();
args = split_line(line);
status = execute(args);
free(line);
free(args);
} while (status);
}
