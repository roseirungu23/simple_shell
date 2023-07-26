#include"main.h"
#include "main.c"
/**
 * exit_status - exits shell with an integer
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 always
 */
int exit_status(int argc, char *argv[])
{
	int status = atoi(argv[1]);

	(void)argc, (void)argv;

	if (argc != 2)
	{
		printf("Usage: %s status, \n", argv[0]);
		return (1);
	}
	if (!is_integer(argv[1]))
	{
		printf("The status must be an integer.\n");
		return (1);
	}
	
	exit(status);
	return (0);
}
/**
 * is_integer - writes an integer status
 * @str: string
 * Return: Success
 */
bool is_integer(const char *str)
{
	char *k;

	if (str == NULL || *str == '\0')
	{
		return (false);
	}
	
	strtol(str, &k, 10);
	return (*k == '\0');
}
