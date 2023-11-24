.text
main:
# grow stack
addi sp, sp, -32
# sp | ---i--- | sp + 4 | ---ch--- |

# i = 1025;
li x10, 1025
sw x10, 0(sp)
# ch = i;
lw x11, 0(sp)
sb x11, 4(sp)

# x11 = ch
lb x11, 4(sp)


# shrink stack
addi sp, sp, 32

# print(x11)
li x10, 1
ecall

# exit()
li x10, 10
ecall

