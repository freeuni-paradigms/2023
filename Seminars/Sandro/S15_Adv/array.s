.text
main:
addi sp, sp , -8


li x10, AreEqual
li x10, 10

call AreEqual




addi sp, sp , 8

# exit()
li x10, 10
ecall



Apple:

# scores[n] = 10;

lw x10, 8(sp)
jalr x10


ret


compareFn:
....
