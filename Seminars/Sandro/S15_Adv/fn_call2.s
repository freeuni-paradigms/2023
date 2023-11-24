.text
main:
addi sp, sp , -32

# caller 
addi sp, sp , -8
li x10, 8
sw x10, 4(sp)
li x10, 5
sw x10, 0(sp)
call add
addi sp, sp, 8
#####

addi sp, sp, 32

mv x11, x10
li x10, 1 # print_int
ecall

# exit()
li x10, 10
ecall


add:
# prologue
addi sp, sp, -12
sw ra, 0(sp)

call foo

# sum = one + two
lw x10, 12(sp) # one
lw x11, 16(sp) # two
add x12, x10, x11 # x12 = one+two
sw x12, 4(sp) # sum = x12
#return sum


# epilogue:

lw x10, 4(sp)
lw ra, 0(sp)
addi sp, sp, 12
ret


foo:
ret




