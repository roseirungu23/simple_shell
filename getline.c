#include "main.h"
/**
* _getline - writes getline function
* Return: line
*/
char *_getline()
{
	static char buff[BUFF_SIZE];
	static int buffpos, buffsize;
	char *line = NULL;
	int linelen = 0;

	while (1)
	{
		if (buffpos >= buffsize)
		{
			buffsize = read(STDIN_FILENO, buff, BUFF_SIZE);
			buffpos = 0;
			if (buffsize <= 0)
			{
				break;
			}
		}
		while (buffpos < buffsize)
		{
			if (buff[buffpos] == '\n')
			{
				buffpos++;
				line[linelen] = '\0';
				return (line);
			}
			line = realloc(line, linelen + 2);
			linelen++;
			buffpos++;
		}
	}
	if (line != NULL)
	{
		line[linelen] = '\0';
	}
	return (line);
}

/**
* main - entry point
* @argc: argument count
* @argv: argument vector
* Return: Success
*/
int main(int argc, char **argv)
{
	char *line;

	(void)argc, (void)argv;

	while ((line = _getline()) != NULL)
	{
		printf("You entered: %s\n", line);
		free(line);
	}
	return (0);
}
