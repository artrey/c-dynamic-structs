#include "dynamic_string.h"

char* create_dynamic_string(const char* str)
{
	size_t len = strlen(str);
	char* ret = (char*)malloc((len + 1) * sizeof(char));
	if (ret == NULL)
		return NULL;
	strncpy(ret, str, len);
	ret[len] = 0;
	return ret;
}
