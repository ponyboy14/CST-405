.text
main:
# -----------------------
li $t0,6
li $t1,5
li $t2,19
li $v0, 1
move $a0,$t0
syscall
li $v0, 1
move $a0,$t1
syscall
li $v0, 1
move $a0,$t2
syscall
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
