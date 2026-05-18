TITLE   EBDA.ASM -- Display EBDA Start Address and Size

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
; Program to display the starting address and size
; of Extended BIOS Data Area (EBDA).
;
;<AMI_FHDR_END>

.model small
.386
.stack 100h

;----------------------------------------------------------------------------
;       DATA SEGMENT
;----------------------------------------------------------------------------
data segment

msg1 db 13,10,"EBDA Information",13,10,13,10,'$'

msg2 db "EBDA Segment Address : 0x$"
msg3 db 13,10,"EBDA Physical Address: 0x$"
msg4 db 13,10,"EBDA Size            : 0x$"

hexbuf db '0000$'
hexbuf32 db '00000000$'

ebda_seg dw ?
ebda_size db ?

data ends
;----------------------------------------------------------------------------


;----------------------------------------------------------------------------
;       CODE SEGMENT
;----------------------------------------------------------------------------
code segment
assume cs:code, ds:data

start:

    mov ax, data
    mov ds, ax

    ;--------------------------------------------------
    ; Print Header
    ;--------------------------------------------------
    mov dx, offset msg1
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; EBDA Segment Pointer
    ; BIOS Data Area
    ; 0040:000E
    ;--------------------------------------------------
    mov ax, 0040h
    mov es, ax

    mov ax, es:[000Eh]
    mov ebda_seg, ax

    ;--------------------------------------------------
    ; Print EBDA Segment Address
    ;--------------------------------------------------
    mov dx, offset msg2
    mov ah, 09h
    int 21h

    mov ax, ebda_seg
    call PrintHexWord

    ;--------------------------------------------------
    ; Calculate Physical Address
    ; Physical = Segment * 16
    ;--------------------------------------------------
    movzx eax, ebda_seg
    shl eax, 4

    ;--------------------------------------------------
    ; Print Physical Address
    ;--------------------------------------------------
    mov dx, offset msg3
    mov ah, 09h
    int 21h

    call PrintHexDword

    ;--------------------------------------------------
    ; Read EBDA Size
    ; First byte of EBDA contains size in KB
    ;--------------------------------------------------
    mov ax, ebda_seg
    mov es, ax

    mov al, es:[0000h]
    mov ebda_size, al

    ;--------------------------------------------------
    ; Print EBDA Size
    ;--------------------------------------------------
    mov dx, offset msg4
    mov ah, 09h
    int 21h

    xor ah, ah
    mov al, ebda_size

    call PrintHexWord

    mov dl, 'h'
    mov ah, 02h
    int 21h

    mov dl, ' '
    int 21h

    mov dl, '('
    int 21h

    mov al, ebda_size
    add al, '0'

    mov dl, al
    int 21h

    mov dl, 'K'
    int 21h

    mov dl, 'B'
    int 21h

    mov dl, ')'
    int 21h

    ;--------------------------------------------------
    ; Exit Program
    ;--------------------------------------------------
    mov ah, 4Ch
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

    mov si, offset hexbuf
    mov cx, 4

hex_loop1:

    rol ax, 4

    mov bl, al
    and bl, 0Fh

    cmp bl, 9
    jbe digit1

    add bl, 7

digit1:
    add bl, '0'

    mov [si], bl
    inc si

    loop hex_loop1

    mov dx, offset hexbuf
    mov ah, 09h
    int 21h

    pop si
    pop dx
    pop cx
    pop bx
    pop ax

    ret

PrintHexWord endp


;----------------------------------------------------------------------------
; PrintHexDword Procedure
;----------------------------------------------------------------------------
PrintHexDword proc

    push eax
    push ebx
    push ecx
    push edx
    push si

    mov si, offset hexbuf32
    mov cx, 8

hex_loop2:

    rol eax, 4

    mov bl, al
    and bl, 0Fh

    cmp bl, 9
    jbe digit2

    add bl, 7

digit2:
    add bl, '0'

    mov [si], bl
    inc si

    loop hex_loop2

    mov dx, offset hexbuf32
    mov ah, 09h
    int 21h

    pop si
    pop edx
    pop ecx
    pop ebx
    pop eax

    ret

PrintHexDword endp

code ends
end start