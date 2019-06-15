#include <stdio.h>
#include "vector.h"

void print_vector(const vector_t* v)
{
	printf("vector at %p with capacity %d and length %d\n",
		v, v->capacity, v->length);
	for (size_t i = 0; i < v->length; ++i)
	{
		printf("V[%d] = %d\n", i, v->arr[i]);
	}
}

void pop_and_print(vector_t* v)
{
	int elem;
	if (pop_back(v, &elem))
	{
		printf("pop success: %d\n", elem);
	}
}

void at_and_print(vector_t* v, size_t index)
{
	int elem;
	if (at(v, index, &elem))
	{
		printf("at from pos %d success: %d\n", index, elem);
	}
}

int main(int argc, char** argv)
{
	vector_t* vec = create_empty_vector();
	print_vector(vec);

	pop_and_print(vec);
	print_vector(vec);

	for (int i = 0; i < 10; ++i)
	{
		push_back(vec, i);
		printf("iter: %d\tcap: %d\tlen: %d\n", i, vec->capacity, vec->length);
	}
	print_vector(vec);
	
	shrink(vec);
	print_vector(vec);

	push_back(vec, 1);
	print_vector(vec);

	pop_and_print(vec);
	print_vector(vec);

	resize(vec, 14);
	print_vector(vec);

	set(vec, 13, 555);
	set(vec, 130, 555);
	print_vector(vec);

	at_and_print(vec, 13);
	at_and_print(vec, 130);

	free_vector(vec);

	return 0;
}
