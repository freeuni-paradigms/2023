.text
main:

# grow stack
addi sp, sp, -4
# int num = 10
li x15, 10
sw x15, 0(sp)

# params for Add function
lw x10, 0(sp) # num
# grow stack for params
addi sp, sp, -8
# store num in stack
sw x10, 0(sp)
# store 45 in stack
li x11, 45
sw x11, 4(sp)

call Add
# shrink stack for params
addi sp, sp, 8

# num = Add(num, 45)
sw x10, 0(sp)

# num = 100
li x11, 100
sw x11, 0(sp)

lw x11, 0(sp)
li x10, 1
ecall

addi sp, sp, 4

li x10, 10
ecall

Add:
# grow stack for locals
addi sp, sp, -12
# save return address to a stack
sw ra, 8(sp)

# one
lw x10, 12(sp)
# two
lw x11, 16(sp)
# sum = one+two
add x10, x10, x11
sw x10, 0(sp)

call My_fun # this overwrites ra register

# restore ra register with our saved return value
lw ra, 8(sp)
# shrink stack for locals
addi sp, sp, 12
ret

My_fun:
ret