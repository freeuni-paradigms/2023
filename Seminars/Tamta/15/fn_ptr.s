.text
#################Main###########################################
main:

addi sp, sp, -12 # grow stack for locals

li x11, CompareStrings # load CompareStrings
lw x12, 4(sp) # load s
lw x13, 0(sp) # load t
addi sp, sp, -12 # grow stack for args
sw x11, 8(sp) # store CompareStrings
sw x13, 4(sp) # store t
sw x12, 0(sp) # store s
call AreEquals
addi sp, sp, 12 # shrink stack for args
sw x10, 8(sp) # same = x10

addi sp, sp, 12 # locals

li x10, 10 # exit
ecall

#################CompareStrings###################################
CompareStrings:
ret # TODO: write impl (impl may call another fn and we'll have to store ra)

#################AreEquals########################################
AreEquals:
addi sp, sp, -4 # grow stack for ra
sw ra, 0(sp) # store ra

addi sp, sp, -8 # grow stack for args
lw x12, 16(sp) # load b
lw x13, 12(sp) # load a
lw x10, 20(sp) # load cmp
sw x12, 4(sp) # store b
sw x13, 0(sp) # store a

jalr x10 # call cmp
addi sp, sp, 8 # shrink stack for args

bne x10, x0, else # if (cmp(a, b) != 0) then jump to else
li x10, 1 # x10 = true
j return: # jump over else block

else:
li x10, 0 # x10 = false

return:
lw ra, 0(sp) # load ra
addi sp, sp, 4 # shrink stack for ra
ret