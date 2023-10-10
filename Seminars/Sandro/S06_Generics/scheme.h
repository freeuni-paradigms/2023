
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	Integer, // 0
	String,  // 1
	List,    // 2
	Nil      // 3
} nodeType; // byte == int

/**
creates a new string first + second
*/
char *ConcatStrings(const char *first, const char *second);

/**
recursively concats all string nodeTypes
*/
char *ConcatAll(nodeType *list);
