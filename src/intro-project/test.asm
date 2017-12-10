	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$112, %rsp
	leaq	L_.str(%rip), %rax
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rax, %rdi
	movb	$0, %al
	callq	_printf
	movl	$5, -20(%rbp)
	movl	$0, -24(%rbp)
	movl	%eax, -104(%rbp)        ## 4-byte Spill
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$5, -24(%rbp)
	jge	LBB0_4
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_3
LBB0_3:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	jmp	LBB0_1
LBB0_4:
	leaq	-96(%rbp), %rax
	leaq	-80(%rbp), %rcx
	leaq	-64(%rbp), %rdx
	movl	$5, -28(%rbp)
	movl	$5, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movl	$6, -80(%rbp)
	movq	%rcx, -72(%rbp)
	movl	$7, -96(%rbp)
	movq	%rax, -88(%rbp)
	movl	_outsideVariable(%rip), %esi
	movl	%esi, -100(%rbp)
	movl	-4(%rbp), %eax
	addq	$112, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__DATA,__data
	.globl	_outsideVariable        ## @outsideVariable
	.p2align	2
_outsideVariable:
	.long	5                       ## 0x5

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Hello world!"


.subsections_via_symbols
