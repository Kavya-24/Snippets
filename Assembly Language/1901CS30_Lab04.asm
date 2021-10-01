#Kavya Goyal 
#1901CS30

.data

numberMsg:      .asciiz  "Enter the number of elements in the array: "
elementsMsg:    .asciiz  "Enter the elements\n";
sortedMsg:      .asciiz  "The sorted array is given by:\n"
space:          .asciiz   " "
    

#t2: for the size of n
#t1 for the start of the array


.text
    main:                                   
        
        li $v0, 4                             #Print string
        la $a0, numberMsg
        syscall

        jal getNum
        
        addi $t0, $v0, 0                       #int n bytes forms tored in t0 
        addi $t5, $t0, 0                       #int n stored in $t5
        addi $t6, $t5,-1                       #n-1 value
        mul $t0, $t0, 4

        sll $a0, $v0, 2                       #Left shift to multiply by 4
        li  $v0, 9                            #v0 now has the address
        syscall 
                
        move $t1, $v0                         
        add $t2, $t1, $t0                  
        addi $t3, $t1, 0                      #t3 is the iterator

        li $v0, 4                             #Print string
        la $a0, elementsMsg
        syscall

        inputLoop:                          # Input the loop
            bge	$t3, $t2, endInputLoop	    # bge - Branch on Greater Than Equal, stops if t3 > 40
            jal getNum                         
            sw $v0, 0($t3)                  # stores in array
            addi $t3, $t3, 4                # add 4 to t3, meaning move to next input
            j inputLoop                     #jump to inputLoop

        endInputLoop:

        
        #Bubble Sort   [n times check for adjacent elements, stop when not swapping anymore]
        #t1 is the start 
        #t2 is the end
        #t3, t4 are i,j Variables
        
        move $s7, $t1                 #Starting Address in s7
        
        li $s0, 0					#initialize counter 1 for loop 1
        move $s6, $t6 				#n - 1
	    li $s1, 0 					#initialize counter 2 for loop 2

	    li $t3, 0					#initialize counter for printing
	    move $t4, $t5               #Start to end


        li $v0, 4                   #Print string
        la $a0, sortedMsg
        syscall

        jal loop

        jal exitLabel

        
    
    loop:
        sll $t7, $s1, 2					#4*j
        add $t7, $s7, $t7 				#The address of the second element = t7 = i + 4j = s7 + shifted t7

        lw $t0, 0($t7)  				#load numbers[j]	
        lw $t1, 4($t7) 					#load numbers[j+1]

        slt $t2, $t0, $t1				#if t0 < t1, t2 = 1, when true else 0 when false
        bne $t2, $zero, increment       #If t0< t1, then we need to increment the counter2

        add $t9, $zero, 1               #Flag
        sw $t1, 0($t7) 					#swap
        sw $t0, 4($t7)
        


    increment:	

        addi $s1, $s1, 1				#increment t1
        sub $s5, $s6, $s0 				#subtract s0 from s6

        bne  $s1, $s5, loop				#if s1 (counter for second loop) does not equal n-1, loop
        


        #If the second counter has reached the n-1 end, move forward and increment
        #If here, the value of t9 is 0 (Not swapped yet again), we can break it
        
        beq $t9,$zero endLoop

        addi $s0, $s0, 1 				#otherwise add 1 to s0
        li $s1, 0 					    #reset s1 to 0
        li $t9, 0

        bne  $s0, $s6, loop				# go back through loop with s1 = s1 + 1
        

    endLoop:
        #Set the terminating conditions
        move $s0, $s6
        bne  $s0, $s6, loop


    print:
        beq $t3, $t4, exitLabel			#if t3 = t4 go to final
        
        lw $t5, 0($s7)					#load from numbers
        
        li $v0, 1					    #print the number
        move $a0, $t5
        syscall

        li $v0, 4                             #Print string
        la $a0, space
        syscall
        
        addi $s7, $s7, 4				#increment through the numbers
        addi $t3, $t3, 1				#increment counter

        j print 


    getNum:                                 # function to take user input
        li $v0, 5                           # Read integer in v0
        syscall
        jr $ra                              # Jump register at end of function


    exitLabel:
        li $v0,10
        syscall
