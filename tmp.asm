.text
main:
j begin
func:
add $t5, $t4,$t3
move $t8, $t5
jr $ra

begin:
li $t0, 3
li $t1, 4
move $t3, $t0
move $t4, $t1

jal func
move $t6, $t8
li $v0, 1
move $a0,$t8
syscall
li $v0,10 
syscall
.end main