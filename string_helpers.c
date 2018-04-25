#include "monty.h"
char *global_var = NULL;
/**
 * get_tokens - get tokens from line
 * @line: line from file
 * @line_number: line number
 *
 * Return: int
 */

char *get_token(char *line)
{
	char delim[2] = "\n ";
	char *token = NULL;

	token = strtok(line, delim);
	printf("first token: %s\n", token);
	global_var = strtok(NULL, delim);
	{
		printf("token: %s\n", token);
		token = strtok(NULL, delim);
	}
	return (token);
}
