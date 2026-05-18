TITLE   SUM.ASM -- Program to sum of 1 to 10

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
; Description: Program to sum numbers from 1 to 10 and display result
; Date: 28/03/2026
;
;<AMI_FHDR_END>
;*************************************************************************

.model small
.stack 100h

;----------------------------------------------------------------------------
;       DATA SEGMENT
;----------------------------------------------------------------------------
data segment

msg db "Sum of numbers from 1 to 10 is: $"

data ends
;----------------------------------------------------------------------------

;----------------------------------------------------------------------------
;       CODE SEGMENT
;----------------------------------------------------------------------------
code segment
assume cs:code, ds:data

start:

    ; Initialize Data Segment
    mov ax, data
    mov ds, ax

    ;----------------------------------------
    ; Initialize registers
    ;----------------------------------------
    mov cx, 10          ; Counter (10 numbers)
    mov ax, 0           ; AX will store sum

    ;----------------------------------------
    ; Loop to calculate sum
    ;----------------------------------------
sum_loop:
    add ax, cx          ; AX = AX + CX
    loop sum_loop       ; CX = CX - 1, repeat until CX = 0

    ; At this point AX = 55
    
    ; ---> FIX ADDED HERE: Save the sum before printing the message
    push ax

    ;----------------------------------------
    ; Display message
    ;----------------------------------------
    mov dx, offset msg
    mov ah, 09h
    int 21h
    
    ; ---> FIX ADDED HERE: Restore the sum back into AX
    pop ax

    ;----------------------------------------
    ; Convert number (AX) to decimal digits
    ;----------------------------------------
    mov bx, 10          ; Divisor = 10
    mov cx, 0           ; Digit counter

convert_loop:
    xor dx, dx          ; Clear DX before division
    div bx              ; AX ÷ 10 → Quotient in AX, Remainder in DX

    push dx             ; Save remainder (digit)
    inc cx              ; Count digits

    cmp ax, 0
    jne convert_loop    ; Continue until quotient = 0

    ;----------------------------------------
    ; Display digits (reverse order)
    ;----------------------------------------
print_loop:
    pop dx              ; Get digit
    add dl, '0'         ; Convert to ASCII

    mov ah, 02h
    int 21h

    loop print_loop

    ;----------------------------------------
    ; Exit program
    ;----------------------------------------
    mov ah, 4Ch
    int 21h

code ends
end start
;----------------------------------------------------------------------------