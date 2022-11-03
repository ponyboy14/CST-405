.text
main:
# -----------------------
li $t0,TPar1 + TPar0 + 34
func: 
li $t1,3
li $t2,4
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
