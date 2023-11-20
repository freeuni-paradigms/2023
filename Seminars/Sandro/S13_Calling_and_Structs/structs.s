.text
main:
addi sp, sp , -8


addi sp, sp , -8
lw x10, 8(sp) # a.n
lw x11, 12(sp) # a.d
sw x10, 0(sp) # p.n
sw x11, 4(sp) # p.d
call Binky
addi sp, sp , 8



addi sp, sp , 8

# exit()
li x10, 10
ecall



Binky:
addi sp, sp, -8
# local.denominator = 1;
li x10, 1
sw x10, 4(sp)
# param.denominator = 2;
li x10, 2
sw x10, 12(sp)
addi sp, sp, 8
ret


