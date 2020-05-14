#include "monty.h"
/**
 * push - adds a new data to the list
 * @stack: head f the list
 * @line_number: file linenumber
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_number)
{
	addnode(stack, line_number);
}
/**
 * addnode - adds a new node to the list
 * @stack: head f the list
 * @line_number: file linenumber
 * Return: head of the list
 */
stack_t *addnode(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;
	stack_t *new_node;

	if (stack == NULL || args.matrix[1] == NULL || !atoi(args.matrix[1]))
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(args.matrix[1]); 
	new_node->next = copy;
	new_node->prev = NULL;
	*stack = new_node;
	if (copy != NULL)
		copy->prev = new_node;
	else
		new_node->prev = NULL;
	copy = *stack;
	return (new_node);
}
/**
 * pint - prints top element of the list
 * @stack: head f the list
 * @line_number: file linenumber
 * Return: no return
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	if (stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", copy->n);
}
/**
 * pop - removes top element of the list
 * @stack: head f the list
 * @line_number: file linenumber
 * Return: no return
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	if (stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = copy->next;
	(*stack)->prev = NULL;
	free(copy);
}
/**
 * swap- swaps the top 2 elements of the list
 * @stack: head f the list
 * @line_number: file linenumber
 * Return: no return
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;
	int aux;

	if (list_len(stack) < 2)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = copy->next->n;
	copy->next->n = copy->n;
	copy->n = aux;
}
