.text
main:

# sp  = sp - 8
addi sp, sp, -8
li x10, 1
sw x10, 0(sp) # arg0=1
li x10, 2
sw x10, 4(sp) # arg1=2
call add
# return value x10
addi sp, sp, 8


mv x11, x10
li x10, 1
ecall

# exit()
li x10, 10
ecall


add:

lw x10, 0(sp)
lw x11, 4(sp)
add x10, x10, x11
ret






