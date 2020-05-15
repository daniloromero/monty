#include "monty.h"
/**
 * tokenfunc - tokenize input from montyfile
 * @line: string to be tokenized
 * Return: matrix with tokenied input
 */
char **tokenfunc(char *line)
{
	char delim[4] = " \n\t";
	char *token = NULL;
	int i = 0;
	int matrixsize = 0;
	char **matrix = NULL;

	token = strtok(line, delim);
	matrixsize = 3;
	matrix = malloc(sizeof(char *) * matrixsize);

	if (matrix == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		free(line);
		fclose(args.monty_file);
		exit(EXIT_FAILURE);
	}
	for (i = 0; token != NULL; i++)
	{
		matrix[i] = token;
		token = strtok(NULL, delim);
	}
	matrix[i] = NULL;
	return (matrix);
}
/**
 * funchandler - function dictionary selector
 * Return: 0 on success 1 for failure
 */
void funchandler(void)
{
	instruction_t key[] = {{"push", push},
			       {"pint", pint},
			       {"pop", pop},
			       {"swap", swap},
			       {"add", add},
			       {"nop", nop},
			       {"pall", pall},
			       {"sub", sub},
			       {"div", divv},
			       {"mul", mul},
			       {"mod", mod},
			       {NULL, NULL}};
	int i = 0;

	for (i = 0; key[i].opcode != NULL; i++)
	{
		if (strcmp(key[i].opcode, args.matrix[0]) == 0)
		{
			key[i].f(&(args.head), args.counter);
			break;
		}
	}
	if (i == 11)
	{
		dprintf(2, "L%d: unknown instruction %s\n", args.counter, args.matrix[0]);
		args.error = -1;
		return;
	}
}
/**
 * _isdigit - verificate if a string contains a digit
 * @arguments:check if is digit
 * Return:a integer
 */
int _isdigit(char *arguments)
{
	int count;

	for (count = 0; arguments[count]; count++)
	{
		if (isdigit(arguments[count]) == 0)
			return (1);
	}
	return (0);
}
