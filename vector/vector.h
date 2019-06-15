#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdint.h>
#include <stdbool.h>

typedef struct vector
{
	int* arr;
	size_t length;
	size_t capacity;
} vector_t;

vector_t* create_empty_vector();
vector_t* create_vector(size_t capacity);

void resize(vector_t* v, size_t size);
void reserve(vector_t* v, size_t capacity);
void shrink(vector_t* v);

void push_back(vector_t* v, int elem);
bool pop_back(vector_t* v, int* elem);

void set(vector_t* v, size_t index, int elem);
bool at(const vector_t* v, size_t index, int* elem);

void free_vector(vector_t* v);

#endif
