#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ConcatStrings(const char *first, const char *second)
{
	char *result = malloc(strlen(first) + strlen(second) + 1);
	strcpy(result, first);
	strcat(result, second);
	return result;
}

int main()
{
	char *string1 = "abc";
	char *string2 = "de";
	char *result = ConcatStrings(string1, string2);
	printf("string1: %s\n", string1);
	printf("string2: %s\n", string2);
	printf("result: %s\n", result);
	printf("addresses (can't be the same):\n");
	printf("1: %p, 2: %p, r: %p\n", string1, string2, result);
}