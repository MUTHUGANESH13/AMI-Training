TITLE   REV.ASM -- Program to reverse a string

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
; Description: Program to take a user string, reverse it using the stack, and display it.
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

    prompt db "Enter a string to reverse: $"
    msg    db 13, 10, "Reversed string: $"

    ;--------------------------------------------------
    ; Buffer structure for reading a string via AH=0Ah
    ;--------------------------------------------------
    input_buffer db 50          ; Byte 0: Max characters allowed
    actual_len   db ?           ; Byte 1: Actual characters typed
    user_string  db 50 dup(?)   ; Byte 2+: The string data

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
    ; Prompt user for string
    ;--------------------------------------------------
    mov dx, offset prompt
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Read string from user
    ;--------------------------------------------------
    mov dx, offset input_buffer
    mov ah, 0Ah
    int 21h

    ;--------------------------------------------------
    ; Check if string is empty
    ;--------------------------------------------------
    mov cl, actual_len         ; Load actual length of typed string into CL
    cmp cl, 0                  ; Did the user just press Enter?
    je exit_program            ; If yes, just exit

    mov ch, 0                  ; Clear CH so CX contains the full 16-bit length
    lea si, user_string        ; Point SI to the start of the typed string

    ;--------------------------------------------------
    ; Step 1: PUSH all characters onto the stack
    ;--------------------------------------------------
push_loop:
    mov al, [si]               ; Get a character from the string
    mov ah, 0                  ; Clear AH (because we must push a 16-bit AX register)
    push ax                    ; Push the character onto the stack
    inc si                     ; Move to the next character in the string
    loop push_loop             ; Repeat until CX becomes 0

    ;--------------------------------------------------
    ; Step 2: POP characters back into the string
    ;--------------------------------------------------
    mov cl, actual_len         ; Reset CX back to the string length
    mov ch, 0
    lea si, user_string        ; Reset SI back to the start of the string

pop_loop:
    pop ax                     ; Pop the top character from the stack
    mov [si], al               ; Overwrite the string memory with the reversed character
    inc si                     ; Move to the next memory slot
    loop pop_loop              ; Repeat until CX becomes 0

    ; Add '$' at the end of the newly reversed string so DOS knows where to stop printing
    mov byte ptr [si], '$'

    ;--------------------------------------------------
    ; Print the result message
    ;--------------------------------------------------
    mov dx, offset msg
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Print the reversed string
    ;--------------------------------------------------
    mov dx, offset user_string
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