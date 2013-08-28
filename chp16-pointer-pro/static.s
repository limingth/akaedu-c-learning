	.file	"static.c"
	.section	.rodata
.LC0:
	.string	"Sunday"
.LC1:
	.string	"Monday"
.LC2:
	.string	"Tuesday"
.LC3:
	.string	"Wednesday"
.LC4:
	.string	"Thursday"
.LC5:
	.string	"Friday"
.LC6:
	.string	"Saturday"
	.data
	.align 4
	.type	msg, @object
	.size	msg, 28
msg:
	.long	.LC0
	.long	.LC1
	.long	.LC2
	.long	.LC3
	.long	.LC4
	.long	.LC5
	.long	.LC6
	.text
.globl get_a_day
	.type	get_a_day, @function
get_a_day:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	msg(,%eax,4), %eax
	movl	%eax, 4(%esp)
	movl	$buf.1417, (%esp)
	call	strcpy
	movl	$buf.1417, %eax
	leave
	ret
	.size	get_a_day, .-get_a_day
	.section	.rodata
.LC7:
	.string	"%s %s\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	pushl	%ebx
	subl	$28, %esp
	movl	$1, (%esp)
	call	get_a_day
	movl	%eax, %ebx
	movl	$0, (%esp)
	call	get_a_day
	movl	$.LC7, %edx
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	printf
	movl	$0, %eax
	addl	$28, %esp
	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret
	.size	main, .-main
	.local	buf.1417
	.comm	buf.1417,20,1
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
