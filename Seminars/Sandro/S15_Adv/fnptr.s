.text
main:
# int same; sp+0
# char *s(4), *t(8);
addi sp, sp, -12

# same = AreEqual(s, t, CompareStrings);
addi sp, sp, -12

lw x10, 16(sp) # s
sw x10, 0(sp)
lw x10, 20(sp) # t
sw x10, 4(sp)
# CompareStrings
li x10, CompareStrings 
sw x10, 8(sp)

call AreEqual
addi sp, sp, 12
# x10
sw x10, 0(sp)

addi sp, sp, 12

CompareStrings:
#return strcmp((char *)a, (char *)b);
ret


AreEqual:
addi sp, sp, -8
sw ra, 0(sp)
# if (cmp(a, b) == 0)
lw x11, 8(sp)
jalr x11 # f() -> x10
# ret = x10
# branch if z10 == 0 to zero label
beqz x10, zero
# return true
li x10, 1
lw ra, 0(sp)
addi sp, sp, 8
ret
zero:
# return false
li x10, 0
lw ra, 0(sp)
addi sp, sp, 8
ret





### exit() ###
li x10, 10
ecall
##############
