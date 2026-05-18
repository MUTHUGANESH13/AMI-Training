TITLE   CHAR.ASM -- Program to find a character in a user-input string

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
; Description: Program to take string and character input and search
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

    prompt1 db "Enter a string: $"
    prompt2 db 13, 10, "Enter a character to search for: $"
    
    msg1 db 13, 10, "Character Found!$"
    msg2 db 13, 10, "Character Not Found.$"

    ;--------------------------------------------------
    ; Buffer structure for reading a string via AH=0Ah
    ;--------------------------------------------------
    input_buffer db 50          ; Byte 0: Max characters allowed to read
    actual_len   db ?           ; Byte 1: Actual characters read (filled by DOS)
    user_string  db 50 dup(?)   ; Byte 2+: The actual string data entered

    search_char  db ?           ; Variable to hold the single character

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

    ;--------------------------------------------------
    ; 1. Prompt user for string
    ;--------------------------------------------------
    mov dx, offset prompt1
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; 2. Read string from user
    ;--------------------------------------------------
    mov dx, offset input_buffer
    mov ah, 0Ah
    int 21h

    ;--------------------------------------------------
    ; 3. Prompt user for character
    ;--------------------------------------------------
    mov dx, offset prompt2
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; 4. Read single character from user
    ;--------------------------------------------------
    mov ah, 01h
    int 21h
    mov search_char, al        ; Save the typed character into our variable

    ;--------------------------------------------------
    ; 5. Initialize for Search
    ;--------------------------------------------------
    lea si, user_string        ; Point SI to the start of the typed string
    mov al, search_char        ; Load the character we are looking for into AL

search_loop:
    mov bl, [si]               ; Load current character from string

    cmp bl, 0Dh                ; Did we hit Carriage Return? (0Dh is the end of user input)
    je not_found               ; If yes, we reached the end without finding it

    cmp bl, al                 ; Compare string character with search character
    je found                   ; If equal, jump to found

    inc si                     ; Move to next character
    jmp search_loop            ; Repeat loop

    ;--------------------------------------------------
    ; If character is found
    ;--------------------------------------------------
found:
    mov dx, offset msg1        ; Load "Found" message
    mov ah, 09h
    int 21h
    jmp exit_program

    ;--------------------------------------------------
    ; If character is not found
    ;--------------------------------------------------
not_found:
    mov dx, offset msg2        ; Load "Not Found" message
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