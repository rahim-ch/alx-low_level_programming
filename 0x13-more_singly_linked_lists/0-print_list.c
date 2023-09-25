#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * print_listint - Display integer values from a listint_t type list.
 * @h: Head of the list.
 *
 * Return: Total nodes traversed in the list.
 */
size_t print_listint(const listint_t *h)
{
    size_t nodes = 0;

    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
        nodes++;
    }

    return (nodes);
}
