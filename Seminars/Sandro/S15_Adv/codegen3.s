.text
main:
# grow stack
addi sp, sp, -32

# ch = 'A'
li x11, 65 # x11 = 65
sb x11, 4(sp) # *(char*)(sp+4) = x11

# i = ch
lb x12, 4(sp) # x11 = signExtend(*(char*)(sp+4))
sw x12, 0(sp)

# x11 = *(char*)(sp)
lb x11, 0(sp)

# shrink stack
addi sp, sp, 32

# print(x11)
li x10, 1
ecall

# exit()
li x10, 10
ecall

