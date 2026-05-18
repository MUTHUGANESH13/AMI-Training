TITLE   KBCW.ASM -- Display Text by Writing to Port 60h/64h

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
; Program to send commands/data through Keyboard Controller
; ports 60h and 64h and display text on screen.
;
;<AMI_FHDR_END>

.model small
.386
.stack 100h

;----------------------------------------------------------------------------
;       DATA SEGMENT
;----------------------------------------------------------------------------
data segment

msg1 db 13,10,"Writing Data to Keyboard Controller Ports 64h and 60h",13,10,'$'
msg2 db 13,10,"Text Displayed Successfully",13,10,'$'

text db 'HELLO BIOS','$'

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
    ; Wait Until Keyboard Controller Input Buffer Empty
    ; Status Port = 64h
    ; Bit1 = Input Buffer Status
    ;--------------------------------------------------
wait_input_empty:

    in al,64h
    test al,02h
    jnz wait_input_empty

    ;--------------------------------------------------
    ; Send Command to Keyboard Controller
    ; Command D2h:
    ; Write Output Buffer
    ;--------------------------------------------------
    mov al,0D2h
    out 64h,al

    ;--------------------------------------------------
    ; Wait Again
    ;--------------------------------------------------
wait_input_empty2:

    in al,64h
    test al,02h
    jnz wait_input_empty2

    ;--------------------------------------------------
    ; Send Data Byte to Port 60h
    ;--------------------------------------------------
    mov al,'A'
    out 60h,al

    ;--------------------------------------------------
    ; Display Text Normally
    ;--------------------------------------------------
    mov dx,offset text
    mov ah,09h
    int 21h

    ;--------------------------------------------------
    ; Success Message
    ;--------------------------------------------------
    mov dx,offset msg2
    mov ah,09h
    int 21h

    ;--------------------------------------------------
    ; Exit Program
    ;--------------------------------------------------
    mov ah,4Ch
    int 21h

code ends
end start