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
			free(cmd);
			free(arg);
			return (0);
		}
		arg = tokenize(cmd);
		if (arg && arg[0])
		{
			if (strcmp(arg[0], "exit") == 0)
			{
				if (arg[1])
					exit(atoi(arg[1]));
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
 * get_full_path - full path of a command
 * @cmd: the ommand
 * Return: pointer
 */
char *get_full_path(const char *cmd)
{
	char *path_env = getenv("PATH");
	char *token, *path = strdup(path_env);
	int len;
	char *full_path;

	if (!path)
		return (NULL);
	if (!path_env)
		return (NULL);
	while (token)
	{
		full_path = malloc(len);
		len = strlen(token) + strlen(cmd) + 2;
		if (!full_path)
		{
			free(path);
			return (NULL);
		}
		printf(full_path, len, "%s/%s", token, cmd);
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
