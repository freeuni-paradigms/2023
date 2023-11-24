.text
main:
# grow stack
addi sp, sp, -32

# | sp----- |
# | ---i--- |

# if(i>=0)
# if i < 0 jump over
lw x10, 0(sp)
blt x10, x0, if_done
# i *= 2
lw x10, 0(sp)
li x11, 2
mul x10, x10, x11
sw x10, 0(sp)
if_done:
# i = 10
li x10, 10
sw x10, 0(sp)

# x11 = i
lw x11, 0(sp)

# shrink stack
addi sp, sp, 32

# print(x11)
li x10, 1
ecall

# exit()
li x10, 10
ecall

