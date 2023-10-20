#include "shell.h"

/**
 * list_lv - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t list_lv(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * str_liist - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **str_liist(list_t *head)
{
	list_t *node = head;
	size_t i = list_lv(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(char_point(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = t_stry(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		char_puts(num_conv(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		char_puts(h->str ? h->str : "(nil)");
		char_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_initi_str - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_initi_str(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = initi_str(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
