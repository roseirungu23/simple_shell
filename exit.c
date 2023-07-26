#include "main.h"
/**
* exit_status - exits shell with an integer
* Return: Always 0(Success).
*/
int exit_status(void)
{
	char *cmd = NULL;
	size_t len;
	char **arg = NULL;
	char *cmd_path = path(arg[0]);

	while (1)
	{
		display_prompt();
		if (getline(&cmd, &len, stdin) == -1)
		{
			return (0);
		}
		arg = tokenize(cmd);
		if (arg && arg[0])
		{
			if (strcmp(arg[0], "exit") == 0)
			{
				if (arg[1])
				{
					exit(atoi(arg[1]));
				}
				else
					exit(0);
			}
			if (cmd_path)
			{
				execve(cmd_path, arg, NULL);
				perror("Error executing command");
				free(cmd_path);
			}
			else
			{
				fprintf(stderr, "cmd not found: %s\n", arg[0]);
			}
		}
		tokens(arg);
		free(cmd);
		len = 0;
	}
	return (0);
}
/**
* getfull_path - full path of a command
* @cmd: the command
* Return: pointer
*/
char *getfull_path(const char *cmd)
{
	char *path;
	char *path_env = getenv("PATH");
	char *token;
	int len;
	char *full_path;

	if (!path_env)
		return (NULL);
	path = strdup(path_env);
	if (!path)
		return (NULL);
	while (token)
	{
		len = strlen(token) + strlen(cmd) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}
		printf(full_path, len, "%s%s", token, cmd);
		if (access(full_path, F_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, DELIMETER);
	}
	free(path);
	return (NULL);
}
