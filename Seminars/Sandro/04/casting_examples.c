#include <stdio.h>

int main()
{
    char ch = 128;
    int int_ch = (int)ch;
    unsigned int unsigned_int_ch = (int)(unsigned char)ch;
    printf("int_ch: %d\n", int_ch);
    printf("unsigned_int_ch: %d\n", unsigned_int_ch);

    short sh = 17;
    int int_sh = (int)sh;
    int int_pointer_sh = *(int *)(&sh);
    printf("int_sh: %d\n", int_sh);
    printf("int_pointer_sh: %d\n", int_pointer_sh);

    int x = 1073741827;
    float x_float = (float)x;
    float x_pointer_float = *(float *)(&x);
    printf("x_float: %f\n", x_float);
    printf("x_pointer_float: %f\n", x_pointer_float);

    float pi = 3.14;
    int pi_int = (int)pi;
    int pi_pointer_int = *(int *)(&pi);
    printf("pi_int: %d\n", pi_int);
    printf("pi_pointer_int: %d\n", pi_pointer_int);

    int y = -1;
    unsigned int unsigned_y = (unsigned int)y;
    unsigned int unsigned_y_pointer = *(unsigned int *)(&y);
    printf("unsigned_y: %u\n", unsigned_y);
    printf("unsigned_y_pointer: %u\n", unsigned_y_pointer);

    return 0;
}