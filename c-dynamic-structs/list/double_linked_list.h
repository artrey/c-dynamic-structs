#ifndef __LIST_DOUBLE_LINKED_LIST_H__
#define __LIST_DOUBLE_LINKED_LIST_H__

#include <stdint.h>
#include <stdbool.h>
#include "../multi_type.h"

// typedef int value_type; // for more perfomance but only one type
typedef multi_type_t value_type;

typedef struct double_linked_list_node
{
	value_type value;
	struct double_linked_list_node* next;
	struct double_linked_list_node* prev;
} dlist_node_t;

typedef struct double_linked_list
{
	dlist_node_t* root;
	size_t length;
	size_t max_length;
} dlist_t;

dlist_t* create_dlist(size_t max_length);

void free_dlist(dlist_t* l);

// update the max_length property:
// if more then current - just update value,
// if less then current - free last nodes.
void dlist_resize(dlist_t* l, size_t max_length);

// add element to list at last
bool dlist_append(dlist_t* l, value_type elem);

// insert element after specified node
bool dlist_insert(dlist_t* l, dlist_node_t* after, value_type elem);

// find node by value
dlist_node_t* dlist_find(dlist_t* l, value_type value);

// remove specified node
bool dlist_remove(dlist_t* l, dlist_node_t* node);

#endif // __LIST_DOUBLE_LINKED_LIST_H__
