# void main(void)
# {
# char *s = malloc(100);
# my_realloc(s, 200);
# // after return, s still holds same address as before
# }
# void my_realloc(void *ptr, int newSize)
# {
# ptr = malloc(newSize); // why isn't this enough to change the pointer?
# }


.text
main:
addi sp, sp , -4

# malloc(100)
addi sp, sp , -4
li x10, 100
sw x10, 0(sp)
call malloc
addi sp, sp, 4
# char *s = x10;
sw x10, 0(sp)

# my_realloc(&s, 200);
addi sp, sp , -8
li x10, 200
sw x10, 4(sp)
addi x10, sp, 8 # x10 <- sp + 8 (addr of s)
sw x10, 0(sp)
call my_realloc
addi sp, sp , 8

addi sp, sp, 4

mv x11, x10
li x10, 1 # print_int
ecall

# exit()
li x10, 10
ecall


my_realloc:
addi sp, sp , -4
sw ra, 0(sp)


addi sp, sp , -4
lw x10, 12(sp) # newSize
sw x10, 0(sp)
call malloc
addi sp, sp, 4
# x10
lw x11, 4(sp) # void* x11 = *ptr
sw x10, 0(x11) # ptr = x10


lw ra, 0(sp)
addi sp, sp , 4
ret




# sp+0 sz
# return x10 -> ptr
malloc:
ret


 # void main(void) {
 #    char *s = malloc(100);
 #    my_realloc(&s, 200);
 # }
 # void my_realloc(void **ptr, int newSize) {
 #    *ptr = malloc(newSize); // why isn't this enough to change the pointer?
 # }

