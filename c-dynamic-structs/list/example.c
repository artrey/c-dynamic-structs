#include "example.h"
#include "list.h"

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
	}
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
		printf("couldn't append to list");
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

	// some actions

	free_list(l);
}

void list_string_example()
{
	multi_type_t mt = { DOUBLE, { 0 } };

	list_t* l = create_list(2);

	// some actions

	free_list(l);
}
