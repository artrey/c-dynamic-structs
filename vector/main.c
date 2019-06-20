#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "vector.h"
#include "dynamic_string.h"

#define SWITCH_PRINT(val) switch ((val).discriminator) { \
	case INT: printf("%d", (val).value.i); break; \
	case FLOAT: printf("%f", (val).value.f); break; \
	case DOUBLE: printf("%lf", (val).value.d); break; \
	case CHAR: printf("%c", (val).value.c); break; \
	case STRING: printf("%s", (val).value.str); break; \
	default: printf("undefined discriminator [%d]", (val).discriminator); break; \
}

void print_vector(const vector_t* v)
{
	printf("vector at %p with capacity %d and length %d\n",
		v, v->capacity, v->length);
	for (size_t i = 0; i < v->length; ++i)
	{
		printf("V[%d] = ", i);
		SWITCH_PRINT(v->arr[i]);
		printf("\n");
	}
}

void pop_and_print(vector_t* v)
{
	value_type elem;
	if (vector_pop_back(v, &elem))
	{
		printf("pop success: ");
		SWITCH_PRINT(elem);
		printf("\n");
	}
}

void at_and_print(vector_t* v, size_t index)
{
	value_type elem;
	if (vector_at(v, index, &elem))
	{
		printf("at from pos %d success: ", index);
		SWITCH_PRINT(elem);
		printf("\n");
	}
}

void vector_int_example()
{
	multi_type_t mt = { INT, { 0 } };

	vector_t* vec = create_empty_vector();
	print_vector(vec);

	pop_and_print(vec);
	print_vector(vec);

	for (size_t i = 0; i < 10; ++i)
	{
		mt.value.i = i;
		vector_push_back(vec, mt);
		printf("iter: %d\tcap: %d\tlen: %d\n", i, vec->capacity, vec->length);
	}
	print_vector(vec);

	vector_shrink(vec);
	print_vector(vec);

	mt.value.i = 1;
	vector_push_back(vec, mt);
	print_vector(vec);

	pop_and_print(vec);
	print_vector(vec);

	vector_resize(vec, 14);
	print_vector(vec);

	mt.value.i = 555;
	vector_set(vec, 13, mt);
	vector_set(vec, 130, mt);
	print_vector(vec);

	at_and_print(vec, 13);
	at_and_print(vec, 130);

	free_vector(vec);
}

void vector_double_example()
{
	multi_type_t mt = { DOUBLE, { 0 } };

	vector_t* vec = create_vector(16);

	for (size_t i = 0; i < 10; ++i)
	{
		mt.value.d = i * sin(i);
		vector_push_back(vec, mt);
		printf("iter: %d\tcap: %d\tlen: %d\n", i, vec->capacity, vec->length);
	}
	print_vector(vec);

	vector_resize(vec, 15);
	print_vector(vec);

	mt.value.d = 23.543;
	vector_set(vec, 14, mt);
	print_vector(vec);

	at_and_print(vec, 8);

	free_vector(vec);
}

void vector_string_example()
{
	multi_type_t mt = { STRING, { 0 } };

	vector_t* vec = create_empty_vector();

	for (size_t i = 0; i < 5; ++i)
	{
		mt.value.str = create_dynamic_string("test string");
		vector_push_back(vec, mt);
		printf("iter: %d\tcap: %d\tlen: %d\n", i, vec->capacity, vec->length);
	}
	print_vector(vec);

	for (size_t i = 0; i < vec->length; ++i)
	{
		if (vec->arr[i].discriminator == STRING)
		{
			free(vec->arr[i].value.str);
		}
	}

	free_vector(vec);
}

int main(int argc, char** argv)
{
	vector_int_example();
	vector_double_example();
	vector_string_example();
	return 0;
}
