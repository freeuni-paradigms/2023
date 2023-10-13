#include <stdio.h>
#include <string.h>

void strcpy1(char dest[], const char source[])
{
	int i=0;
	while(source[i] != 0) {
		dest[i]=source[i];
		i++;
	}
}

int main()
{

    char example[50] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\0";
    char *name = "John Doe";

    // strcpy(example, name);
    strcpy1(example, name);

    printf("Example: %s\n", example);

    return 0;
}
