#include <stdio.h>
#include <string.h>
void strcpy1(char dest[], const char source[])
{   
    int i = 0;
    for (i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0';
}

int main() {
    char example[5];
    char *name = "John Doe";
    char *tmp = "John Doe";

    strcpy1(example, name);

    printf("Example: %s\n", example);
    printf("Example strlen: %lu\n", strlen(example));
    printf("Example sizeof: %lu\n", sizeof(example));

    return 0;
}