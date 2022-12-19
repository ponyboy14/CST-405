.text
main:
# -----------------------
move $t0, $t9 
li $t9, 0 
li $t0,2
move $t1, $t9 
li $t9, 0 
li $t1,3
move $t2, $t9 
li $t9, 0 
li $t2,4
bgt $t0, $t1, IFTRUE1
j ELSE1

IFTRUE1: 
blt $t0, $t2, IFTRUE2
j ELSE2

IFTRUE2: 
li $v0, 1
move $a0,$t2
syscall
j CONTINUEIF2

ELSE2: 
li $v0, 1
move $a0,$t0
syscall
j CONTINUEIF2

CONTINUEIF2: 
j CONTINUEIF1

ELSE1: 
li $v0, 1
move $a0,$t1
syscall
j CONTINUEIF1

CONTINUEIF1: 
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
