.text
main:
# -----------------------
li $t0,6
li $t1,5
li $t2,4
x
move $a0,$t0
y
move $a0,$t1
z
move $a0,$t2
# -----------------
#  Done, terminate program.

li $v0,1   # call code for terminate
syscall      # system call (terminate)
li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
