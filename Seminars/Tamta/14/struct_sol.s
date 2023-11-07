.text
main:
# grow stack for local variables
addi sp, sp, -8

# load args in registers
lw x10, 0(sp) # numerator
lw x11, 4(sp) # denominator
# grow stack for params
addi sp, sp, -8
# save args to stack
sw x10, 0(sp) # numerator
sw x11, 4(sp) # denominator

call Binky

# clean up params
addi sp, sp, 8

# print() print_int=1
lw x11, 0(sp)
li x10, 1
ecall

# clean up locals
addi sp, sp, 8

# exit() exit=10
li x10, 10
ecall

Binky:
# grow stack for locals
addi sp, sp, -8
# local.denominator = 1
li x10, 1
sw x10, 0(sp)
# param.denominator = 2
li x10, 2
sw x10, 12(sp)
ret