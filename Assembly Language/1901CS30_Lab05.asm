#Kavya Goyal 
#1901CS30
#Lab 05 7th September 2021

.data

numberMsg:      .asciiz  "Enter the number of elements in the array: "
elementsMsg:    .asciiz  "Enter the elements\n";
sortedMsg:      .asciiz  "The sorted array using merge sort is given by:\n"
space:          .asciiz   " "

        #t0 address space
        #t1 start address of array
        #t2 end address of array
        #t3 iterator, middle point reference in mergeSort, iterator for printing
        #t4 n 
        #t5,t6 temporary variables for storing values
        #t7,t8,t9 for performing the swap operations
        #s0,s1 start address of L, R in iterations
        #s5 start address of array global
        

    

.text
    main:                                   
        
        li $v0, 4                             #Print string
        la $a0, numberMsg
        syscall

        jal getNum
        
        addi $t0, $v0, 0                       #int n bytes forms tored in t0 
        add $t4, $t0, 0                        #t4 has n
        mul $t0, $t0, 4

        sll $a0, $v0, 2                       #Left shift to multiply by 4
        li  $v0, 9                            #v0 now has the address
        syscall 


        #Start and end address        
        move $t1, $v0                         
        add $t2, $t1, $t0                  
        addi $s5, $t1, 0                       #$s5 also stores the start address of the main array
        
        
        li $v0, 4                             #Print string
        la $a0, elementsMsg
        syscall

        addi $t3, $t1, 0                      

        inputLoop:                          # Input the loop
            bge	$t3, $t2, endInputLoop	    # bge - Branch on Greater Than Equal, stops if t3 > 40
            jal getNum                         
            sw $v0, 0($t3)                  # stores in array
            addi $t3, $t3, 4                # add 4 to t3, meaning move to next input
            j inputLoop                     #jump to inputLoop

        endInputLoop:

                                    
    
        
        li $v0, 4                   #Print string
        la $a0, sortedMsg
        syscall

        
        jal mergeSort

        #s5, t3,t4,t5 used in printing
        li $t3, 0
        
        jal print

        jal exitLabel


    #Stack Pointer will store $ra,l,r,m = (t1,t2,t3)


    mergeSort:

            addi $sp, $sp, -16                        #Adjusting the stack pointer
            sw  $ra, 0($sp)                           #Store the start, end and current return addr
            sw  $t1, 4($sp)                   
            sw  $t2, 8($sp)                    

            sub $t3, $t2, $t1

            ble $t3, 4, mergeSortExit                   #If there is only one element left, we will return it

            
            #Get the address of the mid point
            srl $t3, $t3,  3                            #Divide the address space into half (number)
            sll $t3, $t3, 2                             #multiply by 4 to span address space


            add $t2, $t1, $t3
            sw $t2, 12($sp)

            jal mergeSort                               #MergeSort(l, m)

            lw $t1, 12($sp)
            lw $t2, 8($sp)

            jal mergeSort                               #MergeSort (m,r)

            #Load t1,t2,t3 with l,r,m
            lw $t1, 4($sp)
            lw $t2, 8($sp)
            lw $t3, 12($sp)

            jal merge



    mergeSortExit:

            lw $ra , 0($sp)                             #Fetch the return address from the stack
            addi $sp, $sp, 16                           #Update the stack
            jr $ra                                      #Return address
            

    
    merge:

        addi	$sp, $sp, -16		
        sw	$ra, 0($sp)		
        sw	$t1, 4($sp)         #l		
        sw	$t2, 8($sp)		    #r
        sw	$t3, 12($sp)	    #m
        
        move	$s0, $t1		# Start address of first array (i) Array1 =L
        move	$s1, $t3		# Start address of second array (j) Array2 = R


    mergeLoop:

        lw	$t5, 0($s0)		
	    lw	$t6, 0($s1)		
	    #lw	$t5, 0($t5)		
	    #lw	$t6, 0($t6)		                      #Loading the values at L[i], R[j]

        bgt $t6, $t5, incrementI                  #R[j] > L[i] (We increment i)

        move $t1, $s0                              #Limits for the number
        move $t3, $s1

        jal swapElements 

        addi $s1, $s1, 4



    incrementI: 
        addi $s0, $s0, 4
        lw $t2, 8($sp)                              #Check if this is the ending portion of this sub interval
        
        #Now, if we have reached the end from any where
        bge $s0, $t2, mergeLoopExit
        bge $s1, $t2, mergeLoopExit
        
        b mergeLoop                                #Return


    mergeLoopExit:
            
            lw $ra , 0($sp)                             #Fetch the return address from the stack
            addi $sp, $sp, 16                           #Update the stack
            jr $ra                                      #Return address
    

    swapElements:
        
        ble	$t3, $t1, swapend	

        addi	$t9, $t3, -4	#Previous pointer	
        lw	$t7, 0($t3)		    # Current pointer value
        lw	$t8, 0($t9)		    # Previous pointer value
        
        sw	$t7, 0($t9)		    # Swap values between previous and current
        sw	$t8, 0($t3)		    
        
        move  $t3, $t9		    # move back
        b 	swapElements		# Loop again

	
    swapend:
	        jr	$ra			# Return



    print:
        beq $t3, $t4, exitLabel			      #if t3 = t4 go to final
        
        lw $t5, 0($s5)					      #load from numbers
        
        li $v0, 1					          #print the number
        move $a0, $t5
        syscall

        li $v0, 4                             #Print string
        la $a0, space
        syscall
        
        addi $s5, $s5, 4				      #increment the address
        addi $t3, $t3, 1			          #increment counter

        j print 



    getNum:                                 # function to take user input
        li $v0, 5                           # Read integer in v0
        syscall
        jr $ra                              # Jump register at end of function


    exitLabel:
        li $v0,10
        syscall
