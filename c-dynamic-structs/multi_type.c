#include <string.h>
#include "multi_type.h"

bool equal_multi_type(multi_type_t a, multi_type_t b)
{
	if (a.discriminator != b.discriminator)
		return false;

	switch (a.discriminator)
	{
	case STRING:
		return !strcmp(a.value.str, b.value.str);
	default:
		return a.value.d == b.value.d;
	}
}
