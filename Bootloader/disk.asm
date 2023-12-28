; load 'dh' sectors from drive 'dl' into ES:BX
disk_load:
    pusha
    ; reading from disk requires setting specific values in all registers
    ; so we will overwrite our input parameters from 'dx'. Let's save it
    ; to the stack for later use.
    push dx

    mov ah, 0x02 ; ah <- 0x02 = read
    mov al, dh   ; al <- number of sectors to read 
    mov cl, 0x02 ; cl <- sector 
                 ; 0x01 is boot sector, 0x02 is the first 'available' sector
    mov ch, 0x00 ; ch <- cylinder  dl <- drive number

    mov dh, 0x00 ; dh <- head number 

    int 0x13      ; BIOS interrupt
    jc disk_error ; 

    pop dx
    cmp al, dh    ; Compare number of sectors
    jne sectors_error
    popa
    ret


disk_error:
    mov bx, DISK_ERROR
    call print16
    call print16_nl
    mov dh, ah ; 
    call print16_hex ; 
    jmp disk_loop

sectors_error:
    mov bx, SECTORS_ERROR
    call print16

disk_loop:
    jmp $

DISK_ERROR: db "Disk read error", 0
SECTORS_ERROR: db "Incorrect number of sectors read", 0
