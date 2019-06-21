#ifndef __LIST_LIST_H__
#define __LIST_LIST_H__

#include <stdint.h>
#include <stdbool.h>
#include "../multi_type.h"

// typedef int value_type; // for more perfomance but only one type
typedef multi_type_t value_type;

typedef struct list_node
{
	value_type value;
	struct list_node* next;
} list_node_t;

typedef struct list
{
	list_node_t* root;
	size_t length;
	size_t max_length;
} list_t;

list_t* create_list(size_t max_length);

void free_list(list_t* l);

// update the max_length property:
// if more then current - just update value,
// if less then current - free last nodes.
void list_resize(list_t* l, size_t max_length);

// add element to list at last
bool list_append(list_t* l, value_type elem);

// insert element after specified node
bool list_insert(list_t* l, list_node_t* after, value_type elem);

// find node by value
list_node_t* list_find(list_t* l, value_type value);

// remove specified node
bool list_remove(list_t* l, list_node_t* node);

#endif // __LIST_LIST_H__
