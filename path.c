#include "shell.h"
/**
 * _getenv - function that gets all PATH line
 * @name: environment variable to find
 * Return: Array of PATH line
 */
char *_getenv(char *name)
{
	int i = 0;
	char *ret;

	while (environ[i] != NULL)
	{
		ret = strtok(environ[i], "=");
		if (_strcmp(ret,name) == 0)
		{
			ret = strtok(NULL, "\0");
			break;
		}
		i++;
	}
	return (ret);
}

/**
 * _which - function that locate a command in PATH envir
 * @str1: path where will find the command
 * @str2: Command to find
 * Return: Array of complete path of the command
 */
char *_which(char *str1, char *str2)
{
	int len1, len2, i = 0, b = 0;
	char *newstr;

	len1 = _strlen(str1);
	len2 = _strlen(str2);

	newstr = malloc((len1 + len2) + 1);
	while (str1[i] != '\0')
	{
		newstr[i] = str1[i];
		i++;
	}
	newstr[i] = '/';
	i++;
	while (str2[b] != '\0')
	{
		newstr[i] = str2[b];
		i++;
		b++;
	}
	newstr[i + 1] = '\0';
	return (newstr);
}

/**
 * _path - Function that find the path of shell programs
 * in PATH env variable
 * @argv: input token arguments
 * Return: 0 on success,
 * -1 if command doesn't found
 */
int _path(char **argv)
{
	char *path = NULL;
	char *str = NULL;
	struct stat st;
	unsigned int i;

	path = _getenv("PATH");
	path = strtok(path, ":");
	i = 0;
	while (path != NULL)
	{
		str = _which(path, argv[0]);
		if (stat(str, &st) == 0)
		{
			argv[0] = _strdup(str);
			break;
		}
		path = strtok(NULL, ":");
		i++;
	}
	free(str);
	if (execve(argv[0], argv, NULL) == -1)
		return (-1);
	return (0);
}
