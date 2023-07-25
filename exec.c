#include "main.h"

/**
 * exec - The Function that executes commands.
 * @argv: The argument vector.
 * @av: Commands.
 * Return: Always 0(Success)
 */
int exec(char *argv, char **av)
{
char *cmd_path;
char *cmd;
pid_t pid;
int status;

if (!av[0])
return (0);
cmd = av[0];
if (strcmp(cmd, "exit") == 0)
{
tokens(av);
exit(0);
}
else if (strcmp(cmd, "env") == 0)
print_env();
else
{
cmd_path = cmd;
if (!cmd_path)
{
fprintf(stderr, "%s: not found\n", argv, cmd);
return (0);
}
pid = fork();
if (pid == -1)
perror("Error");
else if (pid == 0)
{
if (execve(cmd_path, av, NULL) == -1)
{
perror("Error");
exit(0);
}
}
else if (waitpid(pid, &status, 0) == -1)
perror("Error");
free(cmd_path);
}
return (0);
}
