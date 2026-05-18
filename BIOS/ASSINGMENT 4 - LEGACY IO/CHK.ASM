TITLE   CMOSCHK.ASM -- Verify CMOS Checksum

;//***********************************************************************
;//*                                                                     *
;//*   Copyright (c) 1985-2025, American Megatrends International LLC.   *
;//*                                                                     *
;//*      All rights reserved. Subject to AMI licensing agreement.       *
;//*                                                                     *
;//***********************************************************************

;<AMI_FHDR_START>
;
; Header:
; Author: Muthuganesh S
; Description:
; Program to calculate CMOS checksum and verify
; whether CMOS checksum is proper or not.
;
;<AMI_FHDR_END>

.model small
.386
.stack 100h

;----------------------------------------------------------------------------
;       DATA SEGMENT
;----------------------------------------------------------------------------
data segment

msg1 db 13,10,"Checking CMOS Checksum...",13,10,'$'

msg2 db 13,10,"Stored CMOS Checksum     : $"
msg3 db 13,10,"Calculated CMOS Checksum : $"

msg_ok  db 13,10,13,10,"CMOS Checksum Status : PROPER",13,10,'$'
msg_bad db 13,10,13,10,"CMOS Checksum Status : INVALID",13,10,'$'

hexbuf db '0000$'

stored_chk dw ?
calc_chk   dw ?

data ends
;----------------------------------------------------------------------------


;----------------------------------------------------------------------------
;       CODE SEGMENT
;----------------------------------------------------------------------------
code segment
assume cs:code, ds:data

start:

    mov ax,data
    mov ds,ax

    ;--------------------------------------------------
    ; Display Start Message
    ;--------------------------------------------------
    mov dx,offset msg1
    mov ah,09h
    int 21h

    ;--------------------------------------------------
    ; Calculate CMOS Checksum
    ;
    ; CMOS Range:
    ; 10h to 2Dh
    ;
    ; Stored checksum:
    ; 2Eh = High Byte
    ; 2Fh = Low Byte
    ;--------------------------------------------------
    xor bx,bx

    mov si,10h

checksum_loop:

    mov ax,si
    out 70h,al

    in al,71h

    xor ah,ah

    add bx,ax

    inc si

    cmp si,2Eh
    jne checksum_loop

    mov calc_chk,bx

    ;--------------------------------------------------
    ; Read Stored CMOS Checksum
    ;--------------------------------------------------
    mov al,2Eh
    out 70h,al
    in al,71h

    mov ah,al

    mov al,2Fh
    out 70h,al
    in al,71h

    mov stored_chk,ax

    ;--------------------------------------------------
    ; Display Stored Checksum
    ;--------------------------------------------------
    mov dx,offset msg2
    mov ah,09h
    int 21h

    mov ax,stored_chk
    call PrintHexWord

    ;--------------------------------------------------
    ; Display Calculated Checksum
    ;--------------------------------------------------
    mov dx,offset msg3
    mov ah,09h
    int 21h

    mov ax,calc_chk
    call PrintHexWord

    ;--------------------------------------------------
    ; Compare Checksums
    ;--------------------------------------------------
    mov ax,stored_chk

    cmp ax,calc_chk
    jne checksum_invalid

checksum_valid:

    mov dx,offset msg_ok
    mov ah,09h
    int 21h

    jmp exit_program

checksum_invalid:

    mov dx,offset msg_bad
    mov ah,09h
    int 21h

exit_program:

    ;--------------------------------------------------
    ; Exit Program
    ;--------------------------------------------------
    mov ah,4Ch
    int 21h


;----------------------------------------------------------------------------
; PrintHexWord Procedure
;----------------------------------------------------------------------------
PrintHexWord proc

    push ax
    push bx
    push cx
    push dx
    push si

    mov si,offset hexbuf
    mov cx,4

hex_loop:

    rol ax,4

    mov bl,al
    and bl,0Fh

    cmp bl,9
    jbe digit

    add bl,7

digit:

    add bl,'0'

    mov [si],bl
    inc si

    loop hex_loop

    mov dx,offset hexbuf
    mov ah,09h
    int 21h

    pop si
    pop dx
    pop cx
    pop bx
    pop ax

    ret

PrintHexWord endp

code ends
end start