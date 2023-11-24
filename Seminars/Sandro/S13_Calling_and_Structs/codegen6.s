.text
main:
# grow stack
addi sp, sp, -32

# for(i=0; i<10; i++)

# i = 0;
# while(i<10){
#  body
#  i++;
# }


# i = 0
sw x0, 0(sp)

while_head:
# if i >= 10 jump to while_done
lw x12, 0(sp)
li x13, 120
bge x12, x13, while_done

# ch = 'a'
li x12, 97
sb x12, 4(sp)

# i++
lw x10, 0(sp)
addi x10, x10, 1
sw x10, 0(sp)

# jump while_head
j while_head

while_done:

# x11 = i
lw x11, 0(sp)

# shrink stack
addi sp, sp, 32

# print(x11)
li x10, 1 
ecall

# exit()
li x10, 10
ecall

