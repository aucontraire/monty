#include "monty.h"
/**
 * main - opens monty file and reads lines
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 success, 1 failure
 */

int main(int argc, char *argv[])
{
	FILE *fp;
	ssize_t bytes_read;
	size_t len = 0;
	char *line = NULL;
	int line_number = 0;
	char *token = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fp = fopen(argv[1], "r");
		if (fp == NULL)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			while ((bytes_read = getline(&line, &len, fp)) != -1)
			{
				line_number++;
				printf("-------------------------\n");
				printf("b_read: %d, line: %s", (int)bytes_read, line);
				token = get_token(line);
				get_func(token);
			}
			printf("bytes read EOF: %d\n", (int)bytes_read);
			free(line);
			fclose(fp);
		}
	}

	return (0);
}
