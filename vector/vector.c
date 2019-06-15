#include <stdlib.h>
#include "vector.h"

#define DEFAULT_CAPACITY 4

vector_t* create_empty_vector()
{
	return create_vector(DEFAULT_CAPACITY);
}

vector_t* create_vector(size_t capacity)
{
	if (capacity == 0)
		return create_empty_vector();
	
	vector_t* v = (vector_t*)malloc(sizeof(vector_t));
	if (!v) 
		return NULL;

	v->arr = NULL;
	v->length = 0;
	reserve(v, capacity);
	
	return v;
}

void resize(vector_t* v, size_t size)
{
	if (size > v->capacity)
	{
		reserve(v, size);
	}
	v->length = size;
}

void reserve(vector_t* v, size_t capacity)
{
	v->capacity = capacity;
	// if v->arr == NULL then realloc same as malloc
	int* t = (int*)realloc(v->arr, v->capacity * sizeof(int));
	v->arr = t;
}

void shrink(vector_t* v)
{
	if (v->length < v->capacity)
	{
		reserve(v, v->length);
	}
}

void push_back(vector_t* v, int elem)
{
	if (v->length >= v->capacity)
	{
		reserve(v, v->capacity * 2);
	}
	v->arr[v->length++] = elem;
}

bool pop_back(vector_t* v, int* elem)
{
	bool result = at(v, v->length - 1, elem);
	if (result)
		--v->length;
	return result;
}

void set(vector_t* v, size_t index, int elem)
{
	if (index < v->length)
	{
		v->arr[index] = elem;
	}
}

bool at(const vector_t* v, size_t index, int* elem)
{
	if (index < v->length)
	{
		*elem = v->arr[index];
		return true;
	}
	return false;
}

void free_vector(vector_t* v)
{
	free(v->arr);
	free(v);
}
