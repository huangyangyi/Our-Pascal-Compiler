	.text
	.file	"pascal_module"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$.Lscanf_format, %edi
	movl	$N, %esi
	xorl	%eax, %eax
	callq	scanf
	movq	%rsp, %rax
	leaq	-16(%rax), %rdi
	movq	%rdi, %rsp
	movl	$1, -16(%rax)
	movq	%rsp, %rax
	leaq	-16(%rax), %rsi
	movq	%rsi, %rsp
	movl	$3, -16(%rax)
	movq	%rsp, %rax
	leaq	-16(%rax), %rdx
	movq	%rdx, %rsp
	movl	$2, -16(%rax)
	movl	$N, %ecx
	callq	move
	xorl	%eax, %eax
	movq	%rbp, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	move                    # -- Begin function move
	.p2align	4, 0x90
	.type	move,@function
move:                                   # @move
	.cfi_startproc
# %bb.0:                                # %label_
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset %rbx, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movl	(%rdi), %eax
	movl	%eax, -32(%rbp)
	movl	(%rsi), %eax
	movl	%eax, -28(%rbp)
	movl	(%rdx), %eax
	movl	%eax, -40(%rbp)
	movl	(%rcx), %eax
	movl	%eax, -36(%rbp)
	cmpl	$1, %eax
	jne	.LBB1_2
# %bb.1:                                # %label_5
	movl	-32(%rbp), %esi
	movl	$.Lprintf_format, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.Lprintf_format.1, %edi
	movl	$.L__unnamed_1, %esi
	xorl	%eax, %eax
	callq	printf
	movl	-28(%rbp), %esi
	movl	$.Lprintf_format.2, %edi
	xorl	%eax, %eax
	callq	printf
	jmp	.LBB1_3
.LBB1_2:                                # %label_15
	movl	-36(%rbp), %eax
	decl	%eax
	movq	%rsp, %rdx
	leaq	-16(%rdx), %rcx
	movq	%rcx, %rsp
	movl	%eax, -16(%rdx)
	leaq	-32(%rbp), %r14
	leaq	-40(%rbp), %rbx
	leaq	-28(%rbp), %r15
	movq	%r14, %rdi
	movq	%rbx, %rsi
	movq	%r15, %rdx
	callq	move
	movl	-32(%rbp), %esi
	movl	$.Lprintf_format.3, %edi
	xorl	%eax, %eax
	callq	printf
	movl	$.Lprintf_format.4, %edi
	movl	$.L__unnamed_2, %esi
	xorl	%eax, %eax
	callq	printf
	movl	-28(%rbp), %esi
	movl	$.Lprintf_format.5, %edi
	xorl	%eax, %eax
	callq	printf
	movl	-36(%rbp), %eax
	decl	%eax
	movq	%rsp, %rdx
	leaq	-16(%rdx), %rcx
	movq	%rcx, %rsp
	movl	%eax, -16(%rdx)
	movq	%rbx, %rdi
	movq	%r15, %rsi
	movq	%r14, %rdx
	callq	move
.LBB1_3:                                # %if_cont
	leaq	-24(%rbp), %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	popq	%rbp
	retq
.Lfunc_end1:
	.size	move, .Lfunc_end1-move
	.cfi_endproc
                                        # -- End function
	.type	N,@object               # @N
	.comm	N,4,4
	.type	.Lprintf_format,@object # @printf_format
	.section	.rodata.str1.1,"aMS",@progbits,1
.Lprintf_format:
	.asciz	"%d"
	.size	.Lprintf_format, 3

	.type	.L__unnamed_1,@object   # @0
.L__unnamed_1:
	.asciz	"->"
	.size	.L__unnamed_1, 3

	.type	.Lprintf_format.1,@object # @printf_format.1
.Lprintf_format.1:
	.asciz	"%s"
	.size	.Lprintf_format.1, 3

	.type	.Lprintf_format.2,@object # @printf_format.2
.Lprintf_format.2:
	.asciz	"%d\n"
	.size	.Lprintf_format.2, 4

	.type	.Lprintf_format.3,@object # @printf_format.3
.Lprintf_format.3:
	.asciz	"%d"
	.size	.Lprintf_format.3, 3

	.type	.L__unnamed_2,@object   # @1
.L__unnamed_2:
	.asciz	"->"
	.size	.L__unnamed_2, 3

	.type	.Lprintf_format.4,@object # @printf_format.4
.Lprintf_format.4:
	.asciz	"%s"
	.size	.Lprintf_format.4, 3

	.type	.Lprintf_format.5,@object # @printf_format.5
.Lprintf_format.5:
	.asciz	"%d\n"
	.size	.Lprintf_format.5, 4

	.type	.Lscanf_format,@object  # @scanf_format
.Lscanf_format:
	.asciz	"%d"
	.size	.Lscanf_format, 3


	.section	".note.GNU-stack","",@progbits
