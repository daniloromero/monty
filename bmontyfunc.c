#include "monty.h"
/**
 * pstr - prints string starting at the top of the stack, followed by new line
 * element of the stack
 * by the top element of the stack
 * @stack: head of the list
 * @line_number: monty file line number
 * Return: no return
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	(void)line_number;
	for (; copy; copy = copy->next)
	{
		if (copy->n > 0 && copy->n < 127)
			printf("%c", copy->n);
		else
			break;
	}
	printf("\n");
}
