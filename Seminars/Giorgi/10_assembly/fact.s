.text

li x10, 10
addi sp, sp, -4
sw x10, 0(sp)
call fact
addi sp, sp, 4
li x10, 1
mv x11, x20
ecall
li x10, 10
ecall

fact:
	lw x10, 0(sp)
	bne x10, x0, abovezero
	addi x20, x0, 1
	ret
abovezero:
	lw x10, 0(sp)
	addi x10, x10, -1
	addi sp, sp, -8
	sw x10, 0(sp)
    sw ra, 4(sp)
	call fact
    lw ra, 4(sp)
    addi sp, sp, 8
	lw x10, 0(sp)
	mul x20, x20, x10
	ret
