.text
main:
addi sp, sp, -8 # grow stack for locals

lw x10, 0(sp)
lw x11, 4(sp)
addi sp, sp, -8 # grow stack for args
sw x10, 0(sp)
sw x11, 4(sp)

call Binky

addi sp, sp, 8 # shrink stack for args

lw x11, 4(sp)
beq x11, x0, success
li x10, 1
ecall
j continue

success:
li x11, 'S'
li x10, 11
ecall

continue:
addi sp, sp, 8 # shrink stack for locals

li x10, 10
ecall

Binky:
addi sp, sp, -8 # grow stack for locals
li x14, 1
sw x14, 4(sp) # local.denominator = 1;
li x15, 2
sw x15, 12(sp) # param.denominator = 2;
addi sp, sp, 8 # shrink stack for locals
ret

