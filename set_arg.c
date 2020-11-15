#include "shell.h"
/**
 *num_of_strings - will find the total number of string on the command line
 *@line: the commands line input
 *Return: returns the total number of strings on the line
 */
int num_of_strings(char *line)
{
	size_t i = 0;
	int delim_count = 0;

	for (i = 0; line[i] != '\0'; i++)
		if (line[i] == ' ')
			delim_count++;
	return (delim_count + 1);
}
/**
 *set_argv - this function will take the given command line and turn it
 * into a an array of strings for execve
 *@line: the command line given
 *Return: returns a pointer to the new array of strings to get sent to main
 */
char **set_argv(char *line)
{
	char *next = NULL;
	char **argv;
	int lgt = 0, i = 0;

	argv = malloc(sizeof(char *) * num_of_strings(line));
	if (argv == NULL)
		return (NULL);
	next = strtok(line, " ");
	while (next != NULL)
	{
		lgt = _strlen(next) + 1;
		argv[i] = malloc(sizeof(char) * lgt);
		if (argv[i] == NULL)
		{
			/*need to free here*/
			return (NULL);
		}
		_strcpy(argv[i], next);
		next = strtok(NULL, " ");
	}
	printf("%s\n", argv[0]);
	argv[i] = NULL;
	return (argv);
}
