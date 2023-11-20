.text
main:
addi sp, sp, -12 # grow stack for locals

lw x10, 8(sp) # x10 = i
li x12, 2
mul x11, x10, x12 # x11 = i * 2
add x11, sp, x11  # x11 = (char*)scores + i*2

li x12, 10
sh x12, 0(x11) # *((char*)scores + i*2) = 10

addi sp, sp, 12 # shrink stack for locals

li x10, 10 
ecall