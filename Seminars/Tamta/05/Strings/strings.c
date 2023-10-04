#include <stdio.h>
#include <stdlib.h>

int strcmp(const char *s1, const char *s2)
{
    while(*s1 != 0 && *s2 != 0 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
    // return *s1 - *s2;
}

char *strcpy(char *dest, const char *src)
{   
    return NULL;
}

size_t strlen(const char *s)
{
    return 0; 
}

char *strcat(char *dest, const char *src)
{
    return NULL;
}

char *strdup(const char *s)
{
    return NULL;
}

void *memset(void *s, int c, size_t n)
{
    return NULL;
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

    // tests casting to unsigned char
    printf("strcmp:\n");
    char *s1_1 = "abcde";  // a in ASCII is 97
    char *s2_2 = "übcde"; // ü in ASCII is 129 
    int strcmpRes_2 = strcmp(s1_1, s2_2);
    if (strcmpRes_2 > 0)
    {
        printf("    s1: %s is greater than s2: %s by %d\n", s1, s2, strcmpRes_2);
    }
    else if (strcmpRes_2 < 0)
    {
        printf("    s1: %s is less than s2: %s by %d\n", s1, s2, strcmpRes_2);
    }
    else
    {
        printf("    s1: %s is equal to s2: %s\n", s1_1, s2_2);
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
    char *newStr = strdup("Strdup First Example");
    printf("    newStr: %s\n", newStr);
    printf("    originStr value address is %p\n", (void *)originStr);
    printf("    newStr value address is %p\n", (void *)newStr);
    printf("\n");

    // memset
    printf("memset:\n");
    char memsetBuffer[50];
    memset((void *)memsetBuffer, 'A', 40);
    printf("    buffer after memset call: %s\n", memsetBuffer);
}