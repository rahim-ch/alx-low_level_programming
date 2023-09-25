#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_nodeint_end - Adds a new node at the end of a listint_t list.
 * @head: Double pointer to the listint_t list.
 * @n: Integer value to put in the new node.
 *
 * Return: Address of the new element, or NULL if it fails.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	listint_t *temp = *head;
	while (temp->next)
		temp = temp->next;

	temp->next = new_node;

	return (new_node);
}
