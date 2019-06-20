#ifndef __MULTI_TYPE_H__
#define __MULTI_TYPE_H__

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

#define PRINT_MULTI_TYPE(val) switch ((val).discriminator) { \
	case INT: printf("%d", (val).value.i); break; \
	case FLOAT: printf("%f", (val).value.f); break; \
	case DOUBLE: printf("%lf", (val).value.d); break; \
	case CHAR: printf("%c", (val).value.c); break; \
	case STRING: printf("%s", (val).value.str); break; \
	default: printf("undefined discriminator [%d]", (val).discriminator); break; \
}

#endif // __MULTI_TYPE_H__
