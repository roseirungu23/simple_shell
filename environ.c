#include "main.h"

/**
 * print_env - function that prints current environment
 * Return: Void
 */

void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
