#include "monty.h"
/**
 * add - adds the top 2 elements of the list and removes head
 * @stack: head of the list
 * @line_number: monty file line number
 * Return: no return
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *copy;
	unsigned int numero = (*stack)->n;

	if (list_len(stack) < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		args.error = -1;
		return;
	}
	pop(stack, args.counter);
	copy = *stack;
	copy->n = numero + copy->n;
}
/**
 * nop - does nothing
 * @stack: head of the list
 * @line_number: monty file line number
 * Return: no return
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

}
/**
 * free_dlistint - singly linked list
 * @head: string - (malloc'ed string)
 * Return: a number
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}


}
/**
 * pall - prints all elements of the list
 * @stack: head of the list
 * @line_number: monty file line number
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	(void)line_number;
	for (; copy; copy = copy->next)
		printf("%d\n", copy->n);
}
/**
 * list_len - size of the list
 * @stack: head of the list
 * Return: int for size of the list
 */
int list_len(stack_t **stack)
{
	stack_t *copy = *stack;
	int i = 0;

	for (; copy; copy = copy->next)
		i++;
	return (i);
}
