#include "monty.h"

stack_t *head = NULL;

/**
 * main - entry point
 * @ac: arguments count
 * @av: list of arguments
 * Return: 0
 */

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openF(av[1]);
	free_n();
	return (0);
}

/**
 * create_n - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_n(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_n - Frees nodes in the stack.
 */
void free_n(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_to_queue - Adds a node to the queue.
 * @new: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **new, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new;
	(*new)->prev = tmp;

}
