; Eza Rasheed
; er6qt
; 04-09-19
; threexplusone.s

    global threexplusone
    
    section.text
    
    
    ; Purpose: This threexplusone routine returns the number of steps required to reach 1
    
    ; Parameter rdi takes in number being inputted into the conjecture
    ; Return register rax returns the count of the number of steps taken, as per the C calling convention
    
    ; OPTIMIZATIONS:
    ; 1. Used fewer x86 instructions: i.e. found out through Google that a number can be checked to see if it's even or odd just by using the "test" instruction (line 31), rather than doing all those extra instructions in lines 32-34
    ; 2. Used "lea" to do multiplication and addition in one instruction rather than doing "imul" first and then "add" for odd numbers
    ; 3. Used bit shift "shr" to divide by 2 for even numbers rather than using idiv
    ; 4. Took out irrelevant "push rdi" instructions and, therefore, did not need to pop anything either, which reduces memory accesses


threexplusone:
    xor rax, rax        ; zero out return register
    cmp rdi, 1          ; base case to check if x = 1
    ;mov rax, 0         ; make ecx = 0 
    je done             ; jump to end if = 1
    jmp recursion       ; else, continue to recursion
    
recursion:
    test rdi, 1         ; performs AND operation to check if number in register is even or odd      (source: https://www.tutorialspoint.com/assembly_programming/assembly_logical_instructions.htm)
    ;mov rdx, rdi
    ;and rdx, 1
    ;cmp rdx, 1
    jne oddNum          ; if number in rdi is one (not equal to 0), go to oddNum
    mov r10, rdi        ; move and store rdi parameter to r10 copy parameter
    shr r10, 1          ; divide by 2
    mov rdi, r10        ; move output from above into rdi parameter
    call threexplusone  ; recursive call
    inc rax             ; increment step count by 1 (count++)
    jmp done
    
oddNum:
    lea rdi, [rdi*3+1]  ; x*3+1
    call threexplusone  ; recursive call
    inc rax             ; increment count by 1 (count++)
    jmp done            
    
done:
    ret                  ; return value(step count)
