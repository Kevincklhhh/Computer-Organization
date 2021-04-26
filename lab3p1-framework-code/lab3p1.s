	.file	"lab3p1.c"
	.globl	array
	.data
	.align 4
	.type	array, @object
	.size	array, 16
array:
	.long	5
	.long	12
	.long	3
	.long	-1
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$48, %esp
	movl	$array, 44(%esp)
	jmp	.L2
.L7:
	movl	44(%esp), %eax
	movl	(%eax), %eax
	movl	%eax, 40(%esp)
	movl	$1, 36(%esp)
	jmp	.L3
.L6:
	movl	40(%esp), %eax
	movl	%eax, 32(%esp)
	movl	36(%esp), %eax
	movl	%eax, 28(%esp)
	jmp	.L4
.L5:
	movl	28(%esp), %eax
	addl	%eax, 36(%esp)
	subl	$1, 32(%esp)
.L4:
	cmpl	$1, 32(%esp)
	jg	.L5
	subl	$1, 40(%esp)
.L3:
	cmpl	$0, 40(%esp)
	jne	.L6
	addl	$4, 44(%esp)
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
.L2:
	movl	44(%esp), %eax
	movl	(%eax), %eax
	cmpl	$-1, %eax
	jne	.L7
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (SUSE Linux) 4.8.5"
	.section	.note.GNU-stack,"",@progbits
