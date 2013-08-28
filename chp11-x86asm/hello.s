# this is my first asm code
/* hehe */
// haha

.globl _start

_start:
	movb $1, %eax
	movb $10, %ebx
	int $0x80
