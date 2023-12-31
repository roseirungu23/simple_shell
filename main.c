#include "main.h"

/**
 * display_prompt - Displays the prompt.
 * Return: void.
 */
void display_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}

/**
 * main - The main function.
 * @argc: The argument count.
 * @argv: The argument vector.
 * Return: Always 0(Success).
 */
int main(int argc, char **argv)
{
	char *cmd = NULL;
	ssize_t status;
	size_t len;
	char **arg;

	(void) argc, (void) argv;

	while (1)
	{
		display_prompt();
		status = getline(&cmd, &len, stdin);

		if (status == -1)
		{
			free(cmd);
			exit(0);
		}
		arg = tokenize(cmd);

		if (arg == NULL)
		{
			continue;
		}
		if (arg[0] != NULL)
		{
			execvp(arg[0], arg);
			perror("Error executing command");
		}
		tokens(arg);
		free(cmd);
		len = 0;
	}
	tokens(arg);
	return (0);
}

/**
 * tokens - Frees the tokens.
 * @args: Array.
 * Return: void.
 */
void tokens(char **args)
{
	int g;

	if (args)
	{
		for (g = 0; args[g] != NULL; g++)
		{
			free(args[g]);
		}
		free(args);
	}
}

/**
 * tokenize - Tokens are made from strings.
 * @str: String.
 * Return: Pointer.
 */
char **tokenize(char *str)
{
	char *token;
	char **args;
	int k = 0;

	args = malloc(sizeof(char *) * BUFF_SIZE);

	if (!args)
	{
		return (NULL);
	}
	token = strtok(str, DELIMETER);

	while (token)
	{
		args[k] = strdup(token);

		if (!args[k])
		{
			tokens(args);
			return (NULL);
		}
		token = strtok(NULL, DELIMETER);
		k++;
	}
	args[k] = NULL;
	return (args);
}
