#include "queue_example.h"
#include "queue.h"
#include "../dynamic_string.h"

void print_queue(const queue_t* q)
{
	printf("queue at %p with max length %d and length %d [%d:%d]\n",
		q, q->max_length, q->length, q->start, q->end);
	for (size_t i = 0; i < q->max_length; ++i)
	{
		printf("Q[%d] = ", i);
		PRINT_MULTI_TYPE(q->arr[i]);
		printf("\n");
	}
}

void queue_int_example()
{
	multi_type_t mt = { INT, { 0 } };
	const size_t length = 4;

	queue_t* q = create_queue(length);

	for (size_t i = 0; i < 2 * length; ++i)
	{
		mt.value.i++;
		queue_enqueue(q, mt);
		print_queue(q);
	}
}

void queue_string_example()
{
	multi_type_t mt = { STRING, { 0 } };
	const size_t length = 5;

	queue_t* q = create_queue(length);
	mt.value.str = create_dynamic_string("Test string");

	for (size_t i = 0; i < length - 1; ++i)
	{
		queue_enqueue(q, mt);
		print_queue(q);
	}

	mt.value.str = create_dynamic_string("Test string 2");
	queue_enqueue(q, mt);
	print_queue(q);

	queue_dequeue(q, &mt);
	printf("Dequeue: ");
	PRINT_MULTI_TYPE(mt);
	printf("\n");
	print_queue(q);

	queue_clear(q);
	print_queue(q);
}