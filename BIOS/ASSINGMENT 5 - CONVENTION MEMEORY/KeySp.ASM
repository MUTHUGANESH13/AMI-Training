TITLE   KEYSTATE.ASM -- Display Keyboard Special Key Status

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
; Program to read and display keyboard special key states
; like Caps Lock, Num Lock, Scroll Lock, Insert,
; Shift, Ctrl and Alt using BIOS keyboard status.
;
;<AMI_FHDR_END>

.model small
.386
.stack 100h

;----------------------------------------------------------------------------
;       DATA SEGMENT
;----------------------------------------------------------------------------
data segment

msg1 db 13,10,"Keyboard Special Key Status",13,10,13,10,'$'

capsmsg    db "Caps Lock    : $"
nummsg     db 13,10,"Num Lock     : $"
scrollmsg  db 13,10,"Scroll Lock  : $"
insertmsg  db 13,10,"Insert Key   : $"
shiftmsg   db 13,10,"Shift Key    : $"
ctrlmsg    db 13,10,"Ctrl Key     : $"
altmsg     db 13,10,"Alt Key      : $"

onmsg  db "ON$"
offmsg db "OFF$"

keystate db ?

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
    ; Display Header
    ;--------------------------------------------------
    mov dx, offset msg1
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; BIOS Keyboard Status
    ; INT 16h Function 02h
    ; Returns keyboard flags in AL
    ;--------------------------------------------------
    mov ah, 02h
    int 16h

    mov keystate, al

    ;--------------------------------------------------
    ; Caps Lock Status (Bit 6)
    ;--------------------------------------------------
    mov dx, offset capsmsg
    mov ah, 09h
    int 21h

    test keystate, 01000000b
    jz caps_off

caps_on:
    mov dx, offset onmsg
    jmp caps_print

caps_off:
    mov dx, offset offmsg

caps_print:
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Num Lock Status (Bit 5)
    ;--------------------------------------------------
    mov dx, offset nummsg
    mov ah, 09h
    int 21h

    test keystate, 00100000b
    jz num_off

num_on:
    mov dx, offset onmsg
    jmp num_print

num_off:
    mov dx, offset offmsg

num_print:
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Scroll Lock Status (Bit 4)
    ;--------------------------------------------------
    mov dx, offset scrollmsg
    mov ah, 09h
    int 21h

    test keystate, 00010000b
    jz scroll_off

scroll_on:
    mov dx, offset onmsg
    jmp scroll_print

scroll_off:
    mov dx, offset offmsg

scroll_print:
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Insert Key Status (Bit 7)
    ;--------------------------------------------------
    mov dx, offset insertmsg
    mov ah, 09h
    int 21h

    test keystate, 10000000b
    jz insert_off

insert_on:
    mov dx, offset onmsg
    jmp insert_print

insert_off:
    mov dx, offset offmsg

insert_print:
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Shift Key Status (Bits 0 and 1)
    ;--------------------------------------------------
    mov dx, offset shiftmsg
    mov ah, 09h
    int 21h

    test keystate, 00000011b
    jz shift_off

shift_on:
    mov dx, offset onmsg
    jmp shift_print

shift_off:
    mov dx, offset offmsg

shift_print:
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Ctrl Key Status (Bit 2)
    ;--------------------------------------------------
    mov dx, offset ctrlmsg
    mov ah, 09h
    int 21h

    test keystate, 00000100b
    jz ctrl_off

ctrl_on:
    mov dx, offset onmsg
    jmp ctrl_print

ctrl_off:
    mov dx, offset offmsg

ctrl_print:
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Alt Key Status (Bit 3)
    ;--------------------------------------------------
    mov dx, offset altmsg
    mov ah, 09h
    int 21h

    test keystate, 00001000b
    jz alt_off

alt_on:
    mov dx, offset onmsg
    jmp alt_print

alt_off:
    mov dx, offset offmsg

alt_print:
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Exit Program
    ;--------------------------------------------------
    mov ah, 4Ch
    int 21h

code ends
end start