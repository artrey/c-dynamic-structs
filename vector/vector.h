#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdint.h>
#include <stdbool.h>

typedef enum value_type
{
	INT,
	FLOAT,
	DOUBLE,
	CHAR,
	STRING,
} value_type_t;

typedef union multi_value
{
	int i;
	float f;
	double d;
	char c;
	char* str;
} multi_value_t;

typedef struct multi_type
{
	value_type_t discriminator;
	multi_value_t value;
} multi_type_t;

// typedef int value_type; // for more perfomance but only one type
typedef multi_type_t value_type;

typedef struct vector
{
	value_type* arr;
	size_t length;
	size_t capacity;
} vector_t;

vector_t* create_empty_vector();
vector_t* create_vector(size_t capacity);

void free_vector(vector_t* v);

void vector_resize(vector_t* v, size_t size);
void vector_reserve(vector_t* v, size_t capacity);
void vector_shrink(vector_t* v);

void vector_push_back(vector_t* v, value_type elem);
bool vector_pop_back(vector_t* v, value_type* elem);

void vector_set(vector_t* v, size_t index, value_type elem);
bool vector_at(const vector_t* v, size_t index, value_type* elem);

#endif // __VECTOR_H__
