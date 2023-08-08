#include "monty.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the head of the list_t list
 * @n: integer to be added to the list_t list
 *
 * Return: address of the new element, or NULL if it failed
 */

stack_t add_node(stack_t **head, const int n)
{
	stack_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}

	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}
