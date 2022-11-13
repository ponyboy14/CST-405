.text
main:
# -----------------------
j begin
li $t0,3
li $t1,4
li $t2,50
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
