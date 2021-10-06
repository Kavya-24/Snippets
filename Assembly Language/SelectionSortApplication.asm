.data
printPart0: .asciiz "\n"
printPart1: .asciiz "Array "
printPart2: .asciiz " (of size "
printPart3: .asciiz "):"
printPart4: .asciiz "\nThe element number "
printPart5: .asciiz " is: "
printPart6: .asciiz "\nThe number of compare operations used is: "


size: .word 10
k: .word 5
array: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
size1: .word 10
k1: .word 6
array1: .word 10, 72, 63, 34, 345, 56, 27, 48, 69, 910
size3: .word 10
k3: .word 2
array3: .word 13, 42, 23, 14, 35, 76, 87, 58, 9, 160

# arrays of info about arrays, and the arrays themselves
sizeArray: .word size, size1, size3
kth: .word k, k1, k3
arrays: .word array, array1, array3

.text
main:
	sub $sp, $sp, 4 
	sw $ra, 0($sp)
	li $t1, 0 

	mainLoop:
		li $t0, 0 
		la $t2, sizeArray #pointer to array of pointers to 'size'
		sll $t4, $t1, 2
		add $t2, $t2, $t4
		lw $t2, 0($t2) # get pointer to size of current array
		lw $t2, 0($t2) # get value of size of current array
		
		la $t3, kth # pointer to array of pointers to 'k'
		sll $t4, $t1, 2
		add $t3, $t3, $t4
		lw $t3, 0($t3) # get pointer
		lw $t3, 0($t3) # get value of k for current array
		
		li $a0, 0 #left
		sub $a1, $t2, 1 #right
		
		la $a3, arrays # pointer to array of arrays
		sll $t4, $t1, 2 
		add $a3, $a3, $t4
		lw $a3, 0($a3) #get array
		
		addi $t1, $t1, 1 #increment array number
		
		sub $t3, $t3, 1 # k--
		jal recursiveSelect # find kth smallest element of current array
		addi $t3, $t3, 1 # k++
		
		jal printResult # print result for current array
		
		blt $t1, 10, mainLoop # loop back untill all array elements are proccessed

	lw $ra, 0($sp) # retrive $ra
	addi $sp, $sp, 4 # adjust $sp
	
	li $v0, 10
	syscall # exit



recursiveSelect:

	sub $sp, $sp, 4
	sw $ra, 0($sp)#save ra
	
	add $a2, $a0, $a1 #pivot = left+right
	srl $a2, $a2, 1 #pivot = pivot/2
	jal partition

	check:
		addi $t0, $t0, 1 #increment number of comparisions
		beq $t3, $v0, found
		addi $t0, $t0, 1 #increment number of comparisions
		blt $t3, $v0, leftHalf

	#else element is in the right half
	rightHalf:
		addi $a0, $v0, 1 # left = pivot+1 
		add $a2, $a0, $a1 #pivot = left+right
		srl $a2, $a2, 1 #pivot = pivot/2
		jal recursiveSelect
		j check

	leftHalf:
		sub $a1, $v0, 1 #right = pivot-1
		add $a2, $a0, $a1 #pivot = left+right
		srl $a2, $a2, 1 #pivot = pivot/2
		jal recursiveSelect
		j check

	found:
		lw $ra, 0($sp) #retrive ra
		addi $sp, $sp, 4
		jr $ra




partition:
	
	sll $t4, $a2, 2
	add $t4, $t4, $a3
	lw $v1, 0($t4) # pivotValue = list[pivotIndex]
	
	# swap list[pivotindex] and list[right] //move pivot to end
	sll $t4, $a1, 2
	add $t4, $t4, $a3
	lw $t5, 0($t4) # temp = list[right]
	sw $v1, 0($t4) # list[right] = pivot (pivot is list[pivotIndex])
	sll $t4, $a2, 2
	add $t4, $t4, $a3
	sw $t5, 0($t4) # list[pivotIndex] = temp (temp is list[right])
	move $v0, $a0 # storeIndex = left
	
	move $t7, $a0 # i = left
	loop:
		sll $t4, $t7, 2
		add $t4, $t4, $a3
		lw $t6, 0($t4) # load list[i]
		addi $t0, $t0, 1 #increment number of comparisions
		bge $t6, $v1, continue #if list[i] < pivotValue, then swap list[storeIndex] and list[i]
		sll $t4, $v0, 2 
		add $t4, $t4, $a3
		lw $t5, 0($t4) # temp = list[storeIndex]
		sw $t6, 0($t4) # list[storeIndex] = list[i]
		sll $t4, $t7, 2
		add $t4, $t4, $a3
		sw $t5, 0($t4) # list[i] = temp
		addi $v0, $v0, 1 # storeIndex++
		
		continue:
			addi $t7, $t7, 1
			blt $t7, $a1, loop #this does not increment number of comparisons
			
	# swap list[right] and list[storeIndex]
	sll $t4, $v0, 2
	add $t4, $t4, $a3
	lw $t5, 0($t4) # temp = list[storeIndex]
	
	sll $t4, $a1, 2
	add $t4, $t4, $a3
	lw $t6, 0($t4) # temp2  = list[right]
	 
	sll $t4, $v0, 2
	add $t4, $t4, $a3
	sw $t6, 0($t4) # list[storeIndex] = list[right]
	
	sll $t4, $a1, 2
	add $t4, $t4, $a3
	sw $t5, 0($t4) # list[right] = temp
	
	# storeIndex is in $v0, pivotValue is in $v1
	jr $ra



printResult: # print result for current array in correct format
	la $a0, printPart1
	li $v0, 4
	syscall # print "Array "
	move $a0, $t1
	li $v0, 1
	syscall # print current array's number
	la $a0, printPart2
	li $v0, 4
	syscall # print " (of size "
	move $a0, $t2
	li $v0, 1
	syscall # print the size of current array
	la $a0, printPart3
	li $v0, 4
	syscall # print "):"
	la $a0, printPart4
	li $v0, 4
	syscall # print "\nThe element number "
	move $a0, $t3
	li $v0, 1
	syscall # print k for current array
	la $a0, printPart5
	li $v0, 4
	syscall # print " is: "
	move $a0, $v1
	li $v0, 1
	syscall # print kth smallest element of current array
	la $a0, printPart6
	li $v0, 4
	syscall # print "\nThe number of compare operations used is: "
	move $a0, $t0
	li $v0, 1
	syscall # print the number of comparisons used
	la $a0, printPart0
	li $v0, 4
	syscall # print "\n"
	syscall # print "\n"
	jr $ra