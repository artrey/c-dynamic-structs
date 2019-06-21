#include "vector/vector_example.h"
#include "list/list_example.h"

int main(int argc, char** argv)
{
	vector_int_example();
	vector_double_example();
	vector_string_example();

	list_int_example();
	list_double_example();
	list_string_example();

	return 0;
}
