#include "main.h"

/**
 * display_prompt - Displays the prompt.
 * Return: void.
 */
void display_prompt(void)
{
if(isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "$ ", 2);
}
}

/**
 * main - The main function.
 * @argc: The argument count.
 * @argv: The argument vector.
 * @envp: The environment variable.
 * Return: Always 0.
 */
int main(int argc, char **argv, char **envp)
{
char *cmd;
int cmd_len;
char *path;
char *full_path;

/**
 * tokens - Frees the tokens.
 * @args: Array.
 * Return: void.
 */
void tokens(char **args)
{
int g;
if(args)
{
for (i = 0; args[g] != NULL; g++)
{
free(args[g]);
}
free(args);
}
}
