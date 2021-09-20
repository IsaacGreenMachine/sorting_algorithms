/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: doubly linked list to be sorted
 * Return: void
 */
#include "sort.h"
void insertion_sort_list(listint_t **list)
{
listint_t *current, *moving;
if (list == NULL || *list == NULL)
return;
current = (*list)->next;
while (current != NULL)
{
moving = current;
if (moving->n < moving->prev->n)
{
current = current->next;
while (moving->prev != NULL && moving->n < moving->prev->n)
{
moveNodeLeft(list, moving);
print_list(*list);
}
}
else
current = current->next;
}
}

/**
 * moveNodeLeft - moves a node left one spot
 * @head: head of list
 * @node: node to be moved
 * Return: void
 */
void moveNodeLeft(listint_t **head, listint_t *node)
{
listint_t *left = node->prev, *right = node->next;
if (left != NULL)
{
node->prev = left->prev;
node->next = left;
left->next = right;
if (left->prev != NULL)
left->prev->next = node;
else
*head = node;
left->prev = node;
if (right != NULL)
right->prev = left;
}

}
