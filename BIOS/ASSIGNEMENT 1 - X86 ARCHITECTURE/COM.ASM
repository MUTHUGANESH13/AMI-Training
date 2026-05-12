TITLE   COM.ASM -- Compare two strings entered by the user

;//***********************************************************************
;//* *
;//* Copyright (c) 1985-2022, American Megatrends International LLC.   *
;//* *
;//* All rights reserved. Subject to AMI licensing agreement.       *
;//* *
;//***********************************************************************
;<AMI_FHDR_START>
;
; Header:
; Author: Muthuganesh s
; Description: Take two strings from user and compare them
; Date: 02/04/2026
;
;<AMI_FHDR_END>
;*************************************************************************

.model small
.stack 100h

;----------------------------------------------------------------------------
;       DATA SEGMENT
;----------------------------------------------------------------------------
data segment

    prompt1 db "Enter the first string: $"
    prompt2 db 13, 10, "Enter the second string: $"
    
    msg_eq  db 13, 10, 13, 10, "Result: Strings are EQUAL!$"
    msg_neq db 13, 10, 13, 10, "Result: Strings are NOT EQUAL.$"

    ;--------------------------------------------------
    ; Buffer for String 1
    ;--------------------------------------------------
    buffer1 db 50          ; Byte 0: Max length allowed
    len1    db ?           ; Byte 1: Actual length typed
    str1    db 50 dup(?)   ; Byte 2+: The string data

    ;--------------------------------------------------
    ; Buffer for String 2
    ;--------------------------------------------------
    buffer2 db 50          ; Byte 0: Max length allowed
    len2    db ?           ; Byte 1: Actual length typed
    str2    db 50 dup(?)   ; Byte 2+: The string data

data ends
;----------------------------------------------------------------------------

;----------------------------------------------------------------------------
;       CODE SEGMENT
;----------------------------------------------------------------------------
code segment
assume cs:code, ds:data

start:

    ;--------------------------------------------------
    ; Initialize Data Segment
    ;--------------------------------------------------
    mov ax, data
    mov ds, ax

    ;--------------------------------------------------
    ; 1. Get First String
    ;--------------------------------------------------
    mov dx, offset prompt1
    mov ah, 09h
    int 21h

    mov dx, offset buffer1
    mov ah, 0Ah
    int 21h

    ;--------------------------------------------------
    ; 2. Get Second String
    ;--------------------------------------------------
    mov dx, offset prompt2
    mov ah, 09h
    int 21h

    mov dx, offset buffer2
    mov ah, 0Ah
    int 21h

    ;--------------------------------------------------
    ; 3. Compare Lengths First (Optimization)
    ;--------------------------------------------------
    mov al, len1         ; Load length of first string
    cmp al, len2         ; Compare with length of second string
    jne not_equal        ; If lengths are different, strings are definitely not equal

    ;--------------------------------------------------
    ; 4. Prepare for Character Comparison
    ;--------------------------------------------------
    mov cl, len1         ; Use the length as our loop counter
    cmp cl, 0            ; Are both strings completely empty? (User just pressed Enter twice)
    je equal             ; If both are empty, technically they are equal!

    mov ch, 0            ; Clear CH so CX has the correct 16-bit loop count
    lea si, str1         ; Point SI to first string data
    lea di, str2         ; Point DI to second string data

    ;--------------------------------------------------
    ; 5. Compare Character by Character
    ;--------------------------------------------------
compare_loop:
    mov al, [si]         ; Get char from string 1
    mov bl, [di]         ; Get char from string 2
    
    cmp al, bl           ; Compare them
    jne not_equal        ; If a mismatch is found, exit immediately to 'not_equal'

    inc si               ; Move to next char in string 1
    inc di               ; Move to next char in string 2
    loop compare_loop    ; Decrease CX, and repeat if CX > 0

    ;--------------------------------------------------
    ; If the loop finishes naturally, all chars matched!
    ;--------------------------------------------------
equal:
    mov dx, offset msg_eq
    mov ah, 09h
    int 21h
    jmp exit_program

    ;--------------------------------------------------
    ; If lengths differ or a char mismatch was found
    ;--------------------------------------------------
not_equal:
    mov dx, offset msg_neq
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Exit program
    ;--------------------------------------------------
exit_program:
    mov ah, 4Ch
    int 21h

code ends
end start
;----------------------------------------------------------------------------