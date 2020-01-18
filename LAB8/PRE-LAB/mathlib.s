; Eza Rasheed
; er6qt
; 03-24-19
; mathlib.s

; Purpose : This file contains the implemetation of the product and power
;           subroutines in which you iteratively and recursively, respectively 
;           find the result of 2 values


; Parameter 1 (in rdi) is the first input value, x
; Parameter 2 (in rsi) is the second input value, y
; Return value is an int that returns the product of 2 values

        global product
        global power
        
        section.text
        
product:
        ; Standard prologue: we do not have to create any local
        ; variables (those values will be kept in registers), and 
        ; we are not using any callee-saved registers.

        ; code from vecsum.s with minor change
        ; Subroutine body:
        xor     rax, rax ; zero out the return register
        xor     r10, r10 ; zero out the counter i
start:
        cmp     r10, rsi ; does r10(counter i) == rsi(y)?
        je      done ; if so, we are done with the loop
        add     rax, rdi ; add rdi to return register rax
        inc     r10 ; increment out counter i/ add 1 to counter
        jmp     start ; we are done with this loop iteration
done:
        ; Standard epilogue: the return value is already in rax, we
        ; do not have any callee-saved registers to restore, and we do not
        ; have any local variables to deallocate, so all we do is return
        ret
        
; Parameter 1 (in rdi) is the first input value, x, which is the base
; Parameter 2 (in rsi) is the second input value, y, which is the exponent
; Return value is an int that returns the result of x raised to the power of y
        
power:
        xor     rax, rax ; zero out the return register
basecase1:
        cmp     rsi, 1 ; if y(2nd prarameter exponent(rsi)) == 1
        jne     startRecursion ; if y != 1, go start recursion
        mov     rax, rdi ; move value of x(rdi) into rax return register to return x, since x^1 = x
        jmp     done1 ; return result
startRecursion:
        dec     rsi ; decrement y by one to get new exponent of y-1
        call    power ; recursive call to power: power(x, y-1)
        mov     rsi, rax ; moves the value(rax) that was returned from the call into the second parameter(rsi) position
        call    product ; call product subroutine in order to multiply x by what is returned by the recursive call power
        jmp     done1 ; return result
done1:
        ret
