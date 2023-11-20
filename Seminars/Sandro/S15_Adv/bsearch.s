.text
bsearch:
addi, sp, sp, -16
sw ra, 0(sp)

#int l = 0;
sw x0, 4(sp)
#int r = n;
lw x10, 20(sp) #n
sw x10, 8(sp) #r
# branch to while_end if l>=r
while_start:
# while (l < r) {
lw x10, 4(sp) #l
lw x11, 8(sp) #r
bge x10, x11, while_end

#   short m = (l + r) / 2;
lw x10, 4(sp) #l
lw x11, 8(sp) #r
add x10, x10, x11
srai x10, x10, 1
sh x10, 12(sp)
#   r = m;
lh x10, 12(sp)
sw x10, 8(sp)

# (Owner *)(cars[m].lights)->name
# cars

lh x11, 12(sp) # m
# m*16
slli x11, x11, 4
lw x10, 16(sp) # cars
# cars + m*16
add x10, x10, x11
# .lights
addi x10, x10, 4 # +4
# ->name
addi x10, x10, 4 # +4
lw x11, 0(x10) # *name
lw x12, 24(sp)
# x11 x12

addi sp, sp, -8
sw x11, 0(sp)
sw x12, 4(sp)
lw x13, 28+8(sp) # cmp_fn
jalr x13
addi sp, sp, 8


# cmp_fn((Owner *)(cars[m].lights)->name, person) < 0


#   if (cmp_fn((Owner *)(cars[m].lights)->name, person) < 0) {

#     l = m;
#   }
# }
j while_start
while_end:

addi, sp, sp, 16
ret

