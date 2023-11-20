.text
main:
# grow stack
addi sp, sp, -32


# ch = 'A'
li x11, 65 # x11 = 65
sb x11, 0(sp) # *(char*)(sp+0) = x11

# x11 = ch
lb x11, 0(sp)


# shrink stack
addi sp, sp, 32

# print_character(x11)
li x10, 11 # 
ecall

# exit()
li x10, 10
ecall

