TITLE   OPROM.ASM -- Detect Option ROM and Transfer Control to VGA ROM

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
; Program to scan Option ROM area, detect available
; Option ROMs, count them and transfer control to
; VGA Option ROM and regain control back.
;
;<AMI_FHDR_END>

.model small
.386
.stack 100h

;----------------------------------------------------------------------------
;       DATA SEGMENT
;----------------------------------------------------------------------------
data segment

msg1 db 13,10,"Scanning Option ROM Area...",13,10,'$'
msg2 db 13,10,"Option ROM Found at Segment : $"
msg3 db 13,10,"Total Option ROM Count      : $"
msg4 db 13,10,"Calling VGA Option ROM...",13,10,'$'
msg5 db 13,10,"Returned From VGA Option ROM",13,10,'$'

hexbuf db '0000$'
countbuf db '00$'

romcount db 0

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
    ; Print Start Message
    ;--------------------------------------------------
    mov dx, offset msg1
    mov ah,09h
    int 21h

    ;--------------------------------------------------
    ; Start Scan from C000h
    ;--------------------------------------------------
    mov ax,0C000h
    mov es,ax

scan_loop:

    ;--------------------------------------------------
    ; Check ROM Signature 55AAh
    ;--------------------------------------------------
    mov bx,0

    mov al, es:[bx]
    cmp al,55h
    jne next_segment

    mov al, es:[bx+1]
    cmp al,0AAh
    jne next_segment

    ;--------------------------------------------------
    ; Valid ROM Found
    ;--------------------------------------------------
    inc romcount

    mov dx, offset msg2
    mov ah,09h
    int 21h

    mov ax, es
    call PrintHexWord

    ;--------------------------------------------------
    ; VGA ROM Usually at C000h
    ;--------------------------------------------------
    mov ax, es
    cmp ax,0C000h
    jne skip_vga

    mov dx, offset msg4
    mov ah,09h
    int 21h

    ;--------------------------------------------------
    ; Transfer Control to VGA ROM
    ; Entry Point = C000:0003
    ;--------------------------------------------------
    pushf

    db 09Ah
    dw 0003h
    dw 0C000h

    mov dx, offset msg5
    mov ah,09h
    int 21h

skip_vga:

next_segment:

    ;--------------------------------------------------
    ; Get ROM Size
    ; Offset 2 = Size in 512-byte blocks
    ;--------------------------------------------------
    mov al, es:[0002h]

    cmp al,0
    jne valid_size

    mov al,1

valid_size:

    xor ah,ah

    ;--------------------------------------------------
    ; Convert to Segment Increment
    ; 512 bytes = 20h paragraphs
    ;--------------------------------------------------
    mov bx,20h
    mul bx

    ;--------------------------------------------------
    ; ES = ES + Size
    ;--------------------------------------------------
    mov bx,es
    add bx,ax
    mov es,bx

    ;--------------------------------------------------
    ; Continue Until F000h
    ;--------------------------------------------------
    mov bx,es
    cmp bx,0F000h
    jb scan_loop

    ;--------------------------------------------------
    ; Print Total ROM Count
    ;--------------------------------------------------
    mov dx, offset msg3
    mov ah,09h
    int 21h

    mov al, romcount
    call PrintHexByte

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

    mov si, offset hexbuf
    mov cx,4

hex_loop1:

    rol ax,4

    mov bl,al
    and bl,0Fh

    cmp bl,9
    jbe digit1

    add bl,7

digit1:

    add bl,'0'

    mov [si],bl
    inc si

    loop hex_loop1

    mov dx, offset hexbuf
    mov ah,09h
    int 21h

    pop si
    pop dx
    pop cx
    pop bx
    pop ax

    ret

PrintHexWord endp


;----------------------------------------------------------------------------
; PrintHexByte Procedure
;----------------------------------------------------------------------------
PrintHexByte proc

    push ax
    push bx
    push dx

    mov bl,al

    shr al,4
    call HexAscii
    mov countbuf[0],al

    mov al,bl
    and al,0Fh
    call HexAscii
    mov countbuf[1],al

    mov dx, offset countbuf
    mov ah,09h
    int 21h

    pop dx
    pop bx
    pop ax

    ret

PrintHexByte endp


;----------------------------------------------------------------------------
; HexAscii Procedure
;----------------------------------------------------------------------------
HexAscii proc

    cmp al,9
    jbe digit2

    add al,7

digit2:

    add al,'0'

    ret

HexAscii endp

code ends
end start