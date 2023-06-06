#include "lists.h"

/**
* delete_nodeint_at_index - Deletes the node at a given index of a linked list.
* @head: Pointer to a pointer to the head of the list.
* @index: Index of the node to be deleted (starting from 0).
*
* Return: 1 if deletion succeeded, -1 if it failed.
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current, *prev;
unsigned int count = 0;

if (head == NULL || *head == NULL)
return (-1);

current = *head;
prev = NULL;

while (current != NULL && count < index)
{
prev = current;
current = current->next;
count++;
}

if (current == NULL)
return (-1);

if (prev == NULL)
*head = current->next;
else
prev->next = current->next;

free(current);
return (1);
}

