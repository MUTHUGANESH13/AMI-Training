TITLE   BIT.ASM -- Program to count 1s in a byte

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
; Description: Program to count the number of 1 bits in a user-input byte
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

    prompt db "Enter a single character: $"
    msg    db 13, 10, "Number of 1 bits in its ASCII value is: $"

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
    ; Prompt user for a character
    ;--------------------------------------------------
    mov dx, offset prompt
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Read a single character from user
    ;--------------------------------------------------
    mov ah, 01h
    int 21h
    ; The ASCII value of the typed character is now in AL

    ;--------------------------------------------------
    ; Setup for counting bits
    ;--------------------------------------------------
    mov cx, 8                  ; Loop 8 times (since a byte has 8 bits)
    mov bl, 0                  ; BL will be our counter for the '1's

    ;--------------------------------------------------
    ; Loop to shift and count
    ;--------------------------------------------------
count_loop:
    shl al, 1                  ; SHL shifts all bits in AL left by 1. 
                               ; The leftmost bit falls into the Carry Flag (CF).

    jnc skip_increment         ; "Jump if No Carry": If CF is 0, skip the next line
    
    inc bl                     ; If CF is 1, increment our counter!

skip_increment:
    loop count_loop            ; Decrease CX. If CX > 0, jump back to count_loop

    ;--------------------------------------------------
    ; Display the result message
    ;--------------------------------------------------
    mov dx, offset msg
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Display the count
    ;--------------------------------------------------
    ; Because a byte only has 8 bits, our max count is 8.
    ; This means we don't need complex division to print it! 
    ; We just add '0' (30h) to convert it to an ASCII character.
    
    mov dl, bl                 ; Move our count from BL to DL for printing
    add dl, '0'                ; Convert the number to an ASCII digit ('0' to '8')
    
    mov ah, 02h                ; DOS interrupt to print a single character
    int 21h

    ;--------------------------------------------------
    ; Exit program
    ;--------------------------------------------------
    mov ah, 4Ch
    int 21h

code ends
end start
;----------------------------------------------------------------------------