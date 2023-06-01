section .data
    format db "Hello, Holberton", 0
    newline db 10

section .text
    global main
    extern printf
    extern exit

main:
    sub rsp, 8  ; Align the stack to 16-byte boundary (if needed)

    ; Print the message
    mov edi, format
    xor eax, eax
    call printf

    ; Print a newline
    mov edi, newline
    xor eax, eax
    call printf

    ; Exit the program
    xor edi, edi
    call exit

