TITLE   KEYBOARD.ASM -- Disable Keyboard for 5 Seconds Using PIC Masking

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
; Disable keyboard interrupt (IRQ1) for 5 seconds by masking
; PIC interrupt and enable it back.
;
;<AMI_FHDR_END>

.model small
.386
.stack 100h

;----------------------------------------------------------------------------
;       DATA SEGMENT
;----------------------------------------------------------------------------
data segment

msg1 db 13,10,"Keyboard Disabled for 5 Seconds...",13,10,'$'
msg2 db 13,10,"Keyboard Enabled Back.",13,10,'$'

oldmask db ?

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
    ; Print Disable Message
    ;--------------------------------------------------
    mov dx, offset msg1
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Read Current PIC Mask
    ; PIC Master Mask Port = 21h
    ; IRQ1 = Keyboard Interrupt
    ;--------------------------------------------------
    in al, 21h
    mov oldmask, al

    ;--------------------------------------------------
    ; Mask Keyboard Interrupt (IRQ1)
    ; Set Bit1 = 1
    ;--------------------------------------------------
    or al, 00000010b
    out 21h, al

    ;--------------------------------------------------
    ; Delay for 5 Seconds
    ; BIOS Timer Tick:
    ; 18.2 ticks/sec
    ; 5 sec ≈ 91 ticks
    ; BIOS Data Area Timer = 0040:006C
    ;--------------------------------------------------
    mov ax, 0040h
    mov es, ax

    mov eax, es:[006Ch]
    add eax, 91

wait_loop:

    cmp es:[006Ch], eax
    jl wait_loop

    ;--------------------------------------------------
    ; Restore Original PIC Mask
    ;--------------------------------------------------
    mov al, oldmask
    out 21h, al

    ;--------------------------------------------------
    ; Print Enable Message
    ;--------------------------------------------------
    mov dx, offset msg2
    mov ah, 09h
    int 21h

    ;--------------------------------------------------
    ; Exit Program
    ;--------------------------------------------------
    mov ah, 4Ch
    int 21h

code ends
end start