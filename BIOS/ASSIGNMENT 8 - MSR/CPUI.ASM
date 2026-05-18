TITLE   CPUINFO.ASM -- Read and Display Processor Information

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
; Program to display processor vendor ID, processor type,
; model and stepping using CPUID instruction.
;
;<AMI_FHDR_END>

.model small
.386
.stack 100h
.586
.model small    ; Fixed: Changed from flat to small for 16-bit DOS
.stack 100h

;----------------------------------------------------------------------------
;       DATA     S E G M E N T
;----------------------------------------------------------------------------
data segment

msg1 db 13,10,'Processor Vendor ID : $'
msg2 db 13,10,'Processor Type      : $'
msg3 db 13,10,'Processor Model     : $'
msg4 db 13,10,'Processor Stepping  : $'

vendor db 13 dup('$')

typeval db ?
modelval db ?
stepval db ?

data ends
;----------------------------------------------------------------------------


;----------------------------------------------------------------------------
;       CODE     S E G M E N T
;----------------------------------------------------------------------------
code segment

assume cs:code, ds:data

start:

main proc

    mov ax, data
    mov ds, ax

    call customfunction

    mov ax,4C00h
    int 21h

main endp


customfunction proc

    ; --- Get Vendor ID ---
    mov eax,0
    cpuid

    mov dword ptr vendor[0], ebx
    mov dword ptr vendor[4], edx
    mov dword ptr vendor[8], ecx

    mov ah,09h
    lea dx,msg1
    int 21h

    mov ah,09h
    lea dx,vendor
    int 21h

    ; --- Get CPU Info ---
    mov eax,1
    cpuid

    ; Get Stepping (Bits 0-3)
    mov ebx,eax
    and bl,0Fh
    mov stepval,bl

    ; Get Model (Bits 4-7)
    mov ebx,eax
    shr ebx,4       ; Fixed: Shift 32-bit register ebx
    and bl,0Fh
    mov modelval,bl

    ; Get Type (Bits 12-13)
    mov ebx,eax
    shr ebx,12      ; Fixed: Shift 32-bit register ebx
    and bl,03h
    mov typeval,bl

    ; --- Print Results ---
    
    ; Type
    mov ah,09h
    lea dx,msg2
    int 21h
    mov dl,typeval
    add dl,30h
    mov ah,02h
    int 21h

    ; Model
    mov ah,09h
    lea dx,msg3
    int 21h
    mov dl,modelval
    add dl,30h      ; Prints symbol if > 9
    mov ah,02h
    int 21h

    ; Stepping
    mov ah,09h
    lea dx,msg4
    int 21h
    mov dl,stepval
    add dl,30h      ; Prints symbol if > 9
    mov ah,02h
    int 21h

    ret

customfunction endp

code ends
end start