.text
main:
# -----------------------
j begin
li $t0,2
li $t1,-3
li $v0, 1
move $a0,$t1
syscall
li $v0, 1
move $a0,$t1
syscall
li $t2,-3
# -----------------
#  Done, terminate program.

li $v0,10   # call code for terminate
syscall      # system call (terminate)
.end main
.data
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
: .float 0.000000
