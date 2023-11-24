.text
main:
# grow stack
addi sp, sp, -80

# x15 <- i


# arr[i] = 7
mv x10, sp
# arr + i*4
# x15 = x15<<2
slli x15, x15, 2
add x10, x10, x15
li x11, 7
sw x11, 0(x10)


# shrink stack
addi sp, sp, 80

# print(x11)
li x10, 1
ecall

# exit()
li x10, 10
ecall

