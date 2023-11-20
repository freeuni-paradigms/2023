.text
bsearch:
addi sp, sp, -16 # grow stack for ra and locals
sw ra, 12(sp) # save ra

sw x0, 8(sp) # l
lw x10, 20(sp) # load n
sw x10, 4(sp) # r

while:
lw x10 4(sp) # load r
lw x11 8(sp) # load l
bge x11, x10, end_while # if (l >= r) jump to end_while

add x10, x10, x11 # x10 = r + l
li x12, 2
div x10, x10, x12 # x10 = (r + l) / 2
sh x10, 0(sp) # short m = (l + r) / 2;
sw x10, 4(sp) # r = m;

lw x11, 16(sp) # cars
li x12, 16
mul x10, x10, x12 # 16*m
add x11, x11, x10 # (char*)cars + 16*m = &cars[m]
addi x11, x11, 8 # (char*)cars + 16*m + 8 = (Owner *)(cars[m].lights)->name (x11 has address of name now char**)
lw x11, 0(x11) # load (char*)cars + 16*m + 8 = (Owner *)(cars[m].lights)->name (x11 has value of name now char*)
lw x12, 24(sp) # person

lw x13, 28(sp) # cmp_fn
addi sp, sp, -8 # grow stack for args
sw x11, 0(sp) # store (Owner *)(cars[m].lights)->name
sw x12, 4(sp) # store person
jalr x13 # call cmp_fn
addi sp, sp, 8 # shrink stack for args

bne x10, x0, else: # if x10 != x0 then else
lh x11, 0(sp) # load m
sw x11, 8(sp) # l = m
else:

j while # loop back

end_while:
lw x10, 8(sp) # x10 = l
lw ra, 12(sp) # load ra
addi sp, sp, 16 # shrink stack for ra and locals
ret