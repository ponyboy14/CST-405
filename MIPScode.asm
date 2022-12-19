.text
main:
# -----------------------
move $t0, $t9 
li $t9, 0 
li $t0,20
WHILE0: 
bgt $t1, -1087079168, WHILELOOP1
j CONTINUEWHILE1

WHILELOOP1: 
move $t2, $t9 
li $t9, 0 
li $t2,48726320
li $v0, 1
move $a0,$t2
syscall
move $t0, $t9 
li $t9, 0 
li $t0,48726464
j WHILE1

CONTINUEWHILE1: 
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
