#include <stdlib.h>
#include "list.h"

list_t* create_list(size_t max_length)
{
	list_t* list = (list_t*)malloc(sizeof(list_t));
	if (list == NULL)
		return NULL;

	list->length = 0;
	list->max_length = max(list->length, max_length);
	list->root = (list_node_t*)malloc(sizeof(list_node_t));
	if (list->root == NULL)
	{
		free(list);
		return NULL;
	}

	list->root->next = NULL;
	return list;
}

list_node_t* remove_node_after(list_t* l, list_node_t* after)
{
	list_node_t* node = after->next;
	after->next = after->next->next;
	--l->length;
	return node;
}

void free_list(list_t* l)
{
	while (l->root->next != NULL)
	{
		free(remove_node_after(l, l->root));
	}
	free(l->root);
	free(l);
}

void list_resize(list_t* l, size_t max_length)
{
	if (l->max_length > max_length && l->length > max_length)
	{
		list_node_t* iter = l->root;
		for (size_t i = 0; i < max_length; ++i)
		{
			iter = iter->next;
		}
		while (iter->next != NULL)
		{
			free(remove_node_after(l, iter));
		}
	}
	l->max_length = max_length;
}

list_node_t* get_last_node(list_t* l)
{
	list_node_t* iter = l->root;
	while (iter->next != NULL)
	{
		iter = iter->next;
	}
	return iter;
}

bool list_append(list_t* l, value_type elem)
{
	return list_insert(l, get_last_node(l), elem);
}

bool list_insert(list_t* l, list_node_t* after, value_type elem)
{
	if (l->length >= l->max_length)
		return false;

	list_node_t* next = after->next;
	after->next = (list_node_t*)malloc(sizeof(list_node_t));
	if (after->next == NULL)
	{
		after->next = next;
		return false;
	}

	after->next->value = elem;
	after->next->next = next;
	++l->length;
	return true;
}

list_node_t* list_find(list_t* l, value_type value)
{
	list_node_t* iter = l->root;
	while (iter->next != NULL && !equal_multi_type(iter->next->value, value))
	{
		iter = iter->next;
	}
	return iter->next;
}

bool list_remove(list_t* l, list_node_t* node)
{
	if (node == NULL)
		return false;
	
	list_node_t* iter = l->root;
	while (iter->next != node && iter->next != NULL)
	{
		iter = iter->next;
	}
	if (iter->next == NULL)
		return false;
	
	free(remove_node_after(l, iter));
	return true;
}
