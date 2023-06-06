#include "lists.h"

/**
* free_listint_safe - Frees a listint_t linked list.
* @head: Pointer to a pointer to the head of the list.
*
* Return: The size of the list that was freed.
*/
size_t free_listint_safe(listint_t **head)
{
listint_t *current, *temp;
size_t count = 0;

if (head == NULL)
return (0);

current = *head;

while (current != NULL)
{
count++;
temp = current;
current = current->next;

if (temp <= current)
{
free(temp);
break;
}

free(temp);
}

*head = NULL;

return (count);
}
