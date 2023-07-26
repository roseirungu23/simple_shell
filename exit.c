#include "main.h"
#include "command_path.c"
#include "main.c"
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
