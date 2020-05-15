#include "monty.h"
/**
 * sub - substract the top of the stack elements from the 2nd and removes head
 * @stack: head of the list
 * @line_number: monty file line number
 * Return: no return
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		args.error = -1;
		return;
	}
	copy->next->n = copy->next->n - copy->n;
	pop(stack, args.counter);
}
/**
 * divv - divides the 2nd element of the stack by the top element of the stack
 * @stack: head of the list
 * @line_number: monty file line number
 * Return: no return
 */
void divv(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		args.error = -1;
		return;
	}
	if (copy->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		args.error = -1;
		return;
	}
	copy->next->n = copy->next->n / copy->n;
	pop(stack, args.counter);
}
/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: head of the list
 * @line_number: monty file line number
 * Return: no return
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		args.error = -1;
		return;
	}
	copy->next->n = copy->next->n * copy->n;
	pop(stack, args.counter);
}
/**
 * mod - computes the rest of the division of the second top
 * element of the stack
 * by the top element of the stack
 * @stack: head of the list
 * @line_number: monty file line number
 * Return: no return
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;

	if (!*stack || !(*stack)->next)
	{
		dprintf(2, "L%d: can't mod, stack too short\n", line_number);
		args.error = -1;
		return;
	}
	if (copy->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		args.error = -1;
		return;
	}
	copy->next->n = copy->next->n % copy->n;
	pop(stack, args.counter);
}
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * element of the stack
 * by the top element of the stack
 * @stack: head of the list
 * @line_number: monty file line number
 * Return: no return
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *copy = *stack;


	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%d: can't pchar, stack empty\n", line_number);
		args.error = -1;
		return;
	}
	if (copy->n < 0 || copy->n > 127)
	{
		dprintf(2, "L%d: can't pchar, value out of range\n", line_number);
		args.error = -1;
		return;
	}
	else
		printf("%c\n", copy->n);
}
