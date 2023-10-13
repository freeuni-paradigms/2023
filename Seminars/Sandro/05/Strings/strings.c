#include <stdio.h>
#include <stdlib.h>

int strcmp(const char *s1, const char *s2)
{
	while(*s1!=0 && *s2!=0 && *s1==*s2){
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

char *strcpy(char *dest, const char *src)
{
	char *dest_start = dest;
	while(*src!=0){
		*dest=*src;
		dest++;
		src++;
	}
	*dest=*src;
	return dest_start;
}

size_t strlen(const char *s)
{
	size_t size = 0;
	while(*s!=0){
		s++;
		size++;
	}
	return size;
}

char *strcat(char *dest, const char *src)
{
	dest = realloc(dest, strlen(dest)+strlen(src)+1);
	strcpy(dest+strlen(dest), src);
	return dest;
}

char *strdup(const char *s)
{
	return strcpy(malloc(strlen(s) + 1), s);
}

void *memset(void *s, int c, size_t n)
{
	char *ptr = s;

	while(n!=0){
		*ptr = c;
		ptr++;
		n--;
	}
	return s;
}

int main()
{
    // strcmp
    printf("strcmp:\n");
    char *s1 = "abcde";
    char *s2 = "bcde";
    int strcmpRes = strcmp(s1, s2);
    if (strcmpRes > 0)
    {
        printf("    s1: %s is greater than s2: %s by %d\n", s1, s2, strcmpRes);
    }
    else if (strcmpRes < 0)
    {
        printf("    s1: %s is less than s2: %s by %d\n", s1, s2, strcmpRes);
    }
    else
    {
        printf("    s1: %s is equal to s2: %s\n", s1, s2);
    }
    printf("\n");

    // strcpy
    printf("strcpy:\n");
    char buffer[50];
    char *strToCopy = "abcde";
    printf("    function returns: %s\n", strcpy(buffer, strToCopy));
    printf("    buffer string after function call: %s\n", buffer);
    printf("\n");

    // strlen
    printf("strlen:\n");
    char *s3 = "Programming";
    char *s4 = "Paradigms";
    printf("    s3: %s len is %zu\n", s3, strlen(s3));
    printf("    s4: %s len is %zu\n", s4, strlen(s4));
    printf("\n");

    // strcat
    printf("strcat:\n");
    char buffer2[50];
    strcpy(buffer2, "Start ");

    printf("    function returns: %s\n", strcat(buffer2, "First"));
    printf("    function returns: %s\n", strcat(buffer2, " Second"));
    printf("    function returns: %s\n", strcat(buffer2, " Third"));
    printf("    buffer2 after function calls: %s\n", buffer2);
    printf("\n");

    // strdup
    printf("strdup:\n");
    char *originStr = "Strdup First Example";
    char *newStr = "Example";
    printf("    originStr value address is %p\n", (void *)originStr);
    printf("    newStr value address is %p\n", (void *)newStr);
    newStr = strdup("Strdup First Example");
	 *newStr = 'B';
    printf("    newStr: %s\n", newStr);
    printf("    originStr value address is %p\n", (void *)originStr);
    printf("    newStr value address is %p\n", (void *)newStr);
    printf("\n");

    // memset
    printf("memset:\n");
    char memsetBuffer[50];
    memset((void *)memsetBuffer, 'A' + 513, 40);
    printf("    buffer after memset call: %s\n", memsetBuffer);
}
