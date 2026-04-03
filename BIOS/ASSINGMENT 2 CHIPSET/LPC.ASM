TITLE   LPC.ASM -- Read and display LPC Decode IO Range

;//***********************************************************************
;//* *
;//* Copyright (c) 1985-2022, American Megatrends International LLC.     *
;//* *
;//* All rights reserved. Subject to AMI licensing agreement.            *
;//* *
;//***********************************************************************
;<AMI_FHDR_START>
;
; Header:
; Author: Muthuganesh s
; Description: Read LPC GEN1_DEC Register (Bus 0, Dev 31, Func 0, Offset 84h)
; Date: 29/03/2026
;
;<AMI_FHDR_END>
;*************************************************************************

.model small
.386                ; REQUIRED: Allows use of 32-bit registers (EAX) in 16-bit mode
.stack 100h

;----------------------------------------------------------------------------
;       DATA SEGMENT
;----------------------------------------------------------------------------
data segment

    msg_start db 13, 10, "Reading LPC GEN1_DEC Register (Bus 0, Dev 31, Fun 0, Off 84h)...$"
    msg_res   db 13, 10, 13, 10, "GEN1_DEC Value: 0x$"
    
    ;--------------------------------------------------
    ; Buffer for 32-bit Hexadecimal Output String
    ;--------------------------------------------------
    hex_buf   db 8 dup('0')  ; 8 bytes for hex characters
              db '$'         ; DOS string terminator

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
    ; Print Start Message
    ;--------------------------------------------------
    mov dx, offset msg_start
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; 1. Calculate and Write PCI Configuration Address
    ; Format: Enable (Bit 31) | Bus 0 | Dev 31 | Func 0 | Offset 84h
    ; Enable = 80000000h
    ; Dev 31 = 0000F800h
    ; Offset = 00000084h
    ; Address = 8000F884h
    ;--------------------------------------------------
    mov dx, 0CF8h           ; Point DX to PCI Config Address Port
    mov eax, 8000F884h      ; Load the GEN1_DEC address
    out dx, eax             ; Write address to port

    ;--------------------------------------------------
    ; 2. Read the PCI Data
    ;--------------------------------------------------
    mov dx, 0CFCh           ; Point DX to PCI Config Data Port
    in eax, dx              ; Read 32-bit register value into EAX

    ;--------------------------------------------------
    ; 3. Convert EAX (Binary) to Hexadecimal String
    ;--------------------------------------------------
    mov di, offset hex_buf  ; Point DI to our output buffer
    mov cx, 8               ; 8 nibbles (hex digits) in a 32-bit register

hex_convert_loop:
    rol eax, 4              ; Rotate highest 4 bits (nibble) into AL
    push eax                ; Save the full EAX state
    
    and al, 0Fh             ; Mask out everything except the bottom nibble
    add al, '0'             ; Add ASCII '0'
    cmp al, '9'             ; Is it a number (0-9)?
    jle store_hex_char      ; If yes, jump to store it
    add al, 7               ; If no, add 7 to convert to 'A'-'F'

store_hex_char:
    mov [di], al            ; Write the ASCII character to the buffer
    inc di                  ; Move to the next byte in the buffer
    pop eax                 ; Restore EAX for the next rotation
    loop hex_convert_loop   ; Decrement CX, loop if not zero

    ;--------------------------------------------------
    ; 4. Print Result Message and Hex Value
    ;--------------------------------------------------
    mov dx, offset msg_res
    mov ah, 09h
    int 21h

    mov dx, offset hex_buf
    mov ah, 09h
    int 21h
    
    ; Print a couple of newlines for clean exit
    mov dl, 13
    mov ah, 02h
    int 21h
    mov dl, 10
    mov ah, 02h
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