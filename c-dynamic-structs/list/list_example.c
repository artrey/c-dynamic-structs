#include <stdio.h>
#include "list_example.h"
#include "list.h"
#include "../dynamic_string.h"

void print_list(const list_t* l)
{
	printf("list at %p with max length %d and length %d\n",
		l, l->max_length, l->length);
	list_node_t* iter = l->root->next;
	size_t idx = 0;
	while (iter != NULL)
	{
		printf("L[%d] = ", idx++);
		PRINT_MULTI_TYPE(iter->value);
		printf(" (address: %p)\n", iter);
		iter = iter->next;
	}
}

void find_and_print(list_t* l, value_type value)
{
	list_node_t* elem = list_find(l, value);
	if (elem != NULL)
	{
		printf("found elem: ");
		PRINT_MULTI_TYPE(elem->value);
	}
	else
	{
		printf("elem not found: ");
		PRINT_MULTI_TYPE(value);
	}
	printf("\n");
}

void list_int_example()
{
	multi_type_t mt = { INT, { 0 } };

	list_t* l = create_list(2);

	mt.value.i = 25;
	list_append(l, mt);
	print_list(l);

	mt.value.i = 250;
	list_append(l, mt);
	print_list(l);

	mt.value.i = 1;
	if (!list_append(l, mt))
	{
		printf("couldn't append to list\n");
	}
	print_list(l);

	list_resize(l, 3);
	print_list(l);

	mt.value.i = 3;
	list_append(l, mt);
	print_list(l);

	list_resize(l, 1);
	print_list(l);

	free_list(l);
}

void list_double_example()
{
	multi_type_t mt = { DOUBLE, { 0 } };

	list_t* l = create_list(2);

	mt.value.d = 43.54;
	list_append(l, mt);
	print_list(l);

	mt.value.d = -11.11;
	list_insert(l, l->root, mt);
	print_list(l);

	find_and_print(l, mt);

	mt.value.d = 43.54;
	find_and_print(l, mt);

	mt.value.d = 43.55;
	find_and_print(l, mt);

	free_list(l);
}

void list_string_example()
{
	multi_type_t mt = { STRING, { 0 } };

	list_t* l = create_list(2);

	mt.value.str = create_dynamic_string("temp string");
	list_append(l, mt);
	print_list(l);

	mt.value.str = create_dynamic_string("temp string 2");
	list_append(l, mt);
	print_list(l);

	char* search_string = create_dynamic_string("temp string");
	mt.value.str = search_string;
	find_and_print(l, mt);
	list_remove(l, list_find(l, mt));
	free(search_string);
	print_list(l);

	search_string = create_dynamic_string("temp string 21");
	mt.value.str = search_string;
	find_and_print(l, mt);
	list_remove(l, list_find(l, mt));
	free(search_string);
	print_list(l);

	free_list(l);
}
