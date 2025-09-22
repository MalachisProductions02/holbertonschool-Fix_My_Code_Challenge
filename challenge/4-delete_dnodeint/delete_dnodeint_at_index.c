#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index index of a dlistint_t list
 * @head: pointer to pointer to head of list
 * @index: index of the node that should be deleted (starting at 0)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    tmp = *head;

    /* Delete the head node */
    if (index == 0)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(tmp);
        return (1);
    }

    /* Traverse to the node at position index */
    for (i = 0; tmp != NULL && i < index; i++)
        tmp = tmp->next;

    if (tmp == NULL)
        return (-1);

    /* Unlink tmp from the list */
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;

    free(tmp);
    return (1);
}
