#include "monty.h"
stack_t *head = NULL;

/**
 * main -The  entry point
 * @argc:The  arguments count
 * @argv:The  list of arguments
 * Return: always return 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node -This Creates a node.
 * @n:The Number to go inside the node.
 * Return:Return Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
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
 * free_nodes -This Frees nodes in the stack.
 */
void free_nodes(void)
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
 * add_to_queue -This Adds a node to the queue.
 * @new_node:The Pointer to the new node.
 * @ln:The line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}