	.file	"lab3p2.c"
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$48, %esp
	call	___main
	movl	$2, 20(%esp)
	movl	$4, 24(%esp)
	movl	$5, 28(%esp)
	movl	$3, 32(%esp)
	movl	$6, 36(%esp)
	movl	$2, 40(%esp)
	movl	$3, 44(%esp)
	movl	44(%esp), %eax
	movl	%eax, 4(%esp)
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	_get_pair
	nop
	leave
	ret
	.globl	_get_pair
	.def	_get_pair;	.scl	2;	.type	32;	.endef
_get_pair:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$1, -12(%ebp)
	jmp	L3
L4:
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_raise2pwr
	movl	%eax, -16(%ebp)
	addl	$8, 8(%ebp)
	addl	$1, -12(%ebp)
L3:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jle	L4
	nop
	nop
	leave
	ret
	.globl	_raise2pwr
	.def	_raise2pwr;	.scl	2;	.type	32;	.endef
_raise2pwr:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$1, -16(%ebp)
	movl	$1, -12(%ebp)
	jmp	L6
L7:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	_mul_op
	movl	%eax, -16(%ebp)
	addl	$1, -12(%ebp)
L6:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jle	L7
	movl	-16(%ebp), %eax
	leave
	ret
	.globl	_mul_op
	.def	_mul_op;	.scl	2;	.type	32;	.endef
_mul_op:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	imull	12(%ebp), %eax
	popl	%ebp
	ret
	.ident	"GCC: (Rev6, Built by MSYS2 project) 10.2.0"
