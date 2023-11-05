#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given
 * index in a dlistint_t list.
 * @head: A pointer to a pointer to the head of the dlistint_t list.
 * @index: The index of the node to delete, starting from 0.
 *
 * Return: 1 if the node was deleted successfully, or -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int count = 0;

	if (*head == NULL)
	{
	return (-1);
	}

	if (index == 0)
	{
	*head = current->next;

	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}

	free(current);
	return (1);
	}

	while (current != NULL && count < index)
	{
	current = current->next;
	count++;
	}

	if (current == NULL)
	{
	return (-1);
	}

	current->prev->next = current->next;

	if (current->next != NULL)
	{
	current->next->prev = current->prev;
	}
	free(current);
	return (1);
}
