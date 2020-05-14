#include "monty.h"
linehead args;

/**
 * main - entry point for monty language interpreter
 * @argc: argument counter
 * @argv: arguments values
 * Return: 0 on succes
 */

int main(int argc, char *argv[])
{
	ssize_t lines = 0;
	char *line = NULL;
	size_t line_size = 0;

	args.counter = 0;
	args.head = NULL;
	args.matrix = NULL;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	args.monty_file = fopen(argv[1], "r");
	if (args.monty_file == NULL)
	{
		printf("Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (lines >= 0)
	{
		args.matrix = NULL;
		lines = getline(&line, &line_size, args.monty_file);
		if (lines <= 0)
			break;
		args.counter += 1;
		args.matrix = tokenfunc(line);
		funchandler();
		free(args.matrix);
	}
	free(line);
	free_dlistint(args.head);
	fclose(args.monty_file);
	return (0);
}
