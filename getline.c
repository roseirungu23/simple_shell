#include "main.h"
/**
 * custom_getline - writes getline function
 * Return: NULL
 */
char *custom_getline(void)
{
	static char buffer[BUFF_SIZE];
	static int pos, length;
	char *line = NULL, *input;
	int line_len = 0;

	if (pos >= length)
	{
		length = read(0, buffer, BUFF_SIZE);
		if (length <= 0)
		{
			return (NULL);
		}
		pos = 0;
	}
	line = (char *)malloc(BUFF_SIZE);
	if (line == NULL)
	{
		fprintf(stderr, "Memory allocation error.\n");
		exit(EXIT_FAILURE);
	}
	while (pos < length && buffer[pos] != '\n')
	{
		line[line_len++] = buffer[pos++];
	}
	line[line_len] = '\0';
	if (pos < length && buffer[pos] == '\n')
	{
		pos++;
	}
	printf("Type a text:\n");
	while ((input = custom_getline()) != NULL)
	{
		if (strcmp(input, "quit") == 0)
		{
			free(input);
			break;
		}
		printf("You entered: %s\n", input);
		free(input);
	}
	return (0);
}
