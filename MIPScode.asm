.text
main:
# -----------------------
j begin
func: 
addi $t0, $s0, 34
add $t0, $t0, $s1
move $t9, $t0
jr $ra
begin:
li $t1,74
li $t2,4
li $s0, 4
li $s1, 74
jal func
continue0:
move $t3, $t9
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
