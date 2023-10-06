
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	Integer,
	String,
	List,
	Nil
} nodeType;

/**
creates a new string first + second
*/
char *ConcatStrings(const char *first, const char *second);

/**
recursively concats all string nodeTypes
*/
char *ConcatAll(nodeType *list);
