#include <stdlib.h>
#include "lists.h"

/**
 * list_len - Determines the length of a list_t list.
 * @h: Start node of the list.
 *
 * Return: Total nodes in the list.
 */

size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}

