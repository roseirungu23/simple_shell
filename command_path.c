#include "main.h"
#define DELIMETER ";"

/**
 * path - The FULL path of a command.
 * @cmd: Command.
 *
 * Return: Pointer.
 */

char *path(const char *cmd)
{
char *path;
char *token;
char *full_path;
char *path_env;
int len;

if (strchr(cmd, '/') != NULL)
{
if (access(cmd, F_OK) == 0)
return (strdup(cmd));
return (NULL);
}
path_env = getenv("PATH");
if (!path_env)
{
return (NULL);
}
path = strdup(path_env);

token = strtok(path, DELIMETER);

while (token)
{
len = strlen(token) + strlen(cmd) + 2;
full_path = malloc(sizeof(char) * len);
if (!full_path)
{
free(path);
return (NULL);
}
printf(full_path, "%s/%s", token, cmd);
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
