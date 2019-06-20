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
	vector_reserve(v, capacity);
	
	return v;
}

void free_vector(vector_t* v)
{
	free(v->arr);
	free(v);
}

void vector_resize(vector_t* v, size_t size)
{
	if (size > v->capacity)
	{
		vector_reserve(v, size);
	}
	v->length = size;
}

void vector_reserve(vector_t* v, size_t capacity)
{
	v->capacity = capacity;
	// if v->arr == NULL then realloc same as malloc
	value_type* t = (value_type*)realloc(v->arr, v->capacity * sizeof(value_type));
	v->arr = t;
}

void vector_shrink(vector_t* v)
{
	if (v->length < v->capacity)
	{
		vector_reserve(v, v->length);
	}
}

void vector_push_back(vector_t* v, value_type elem)
{
	if (v->length >= v->capacity)
	{
		vector_reserve(v, v->capacity * 2);
	}
	v->arr[v->length++] = elem;
}

bool vector_pop_back(vector_t* v, value_type* elem)
{
	bool result = vector_at(v, v->length - 1, elem);
	if (result)
		--v->length;
	return result;
}

void vector_set(vector_t* v, size_t index, value_type elem)
{
	if (index < v->length)
	{
		v->arr[index] = elem;
	}
}

bool vector_at(const vector_t* v, size_t index, value_type* elem)
{
	if (index < v->length)
	{
		*elem = v->arr[index];
		return true;
	}
	return false;
}
