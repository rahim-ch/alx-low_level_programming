#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL.
 * @head: Double pointer to the listint_t list to be freed and set to NULL.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (!head)
		return;
	if (*head)
	{
		temp = *head;
		*head = NULL;
		free_listint(temp);
		return;
	}
}
void free_listint(listint_t *head)
{
	if (!head)
		return;
	free_listint(head->next);
	free(head);

