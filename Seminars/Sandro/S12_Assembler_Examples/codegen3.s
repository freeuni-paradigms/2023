.text
main:
# grow stack
addi sp, sp, -32
# sp | ---i--- | sp + 4 | ---ch--- |

# ch = 'A'
li x10, 65
sb x10, 4(sp)

# i = ch
lb x11, 4(sp)
sw x11, 0(sp)


# shrink stack
addi sp, sp, 32

# print(x11)
li x10, 1
ecall

# exit()
li x10, 10
ecall

