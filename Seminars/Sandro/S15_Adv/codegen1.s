.text
main:
# grow stack
addi sp, sp, -32

# i = 6 i is stored at addr sp

li x10, 6 # x10 = 6
sw x10, 0(sp) # *(int*)(sp+0) = x10

# i++
lw x10, 0(sp) 
# x10=x10+1
addi x10, x10, 1 # x10 = x10 + 1
sw x10, 0(sp)

lw x11, 0(sp)

# shrink stack
addi sp, sp, 32

# print(x11) print=1
li x10, 1 # x10 = 1-> print
ecall

# exit() exit=10
li x10, 10
ecall

