	.text
	.file	"pascal_module"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %for_start
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	$.Lprintf_format, %edi
	movl	$.L__unnamed_1, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$.Lscanf_format, %edi
	movl	$a, %esi
	xorl	%eax, %eax
	callq	scanf
	movss	a(%rip), %xmm0          # xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, s(%rip)
	movss	%xmm0, max(%rip)
	movss	%xmm0, min(%rip)
	movl	$2, i(%rip)
	.p2align	4, 0x90
.LBB0_2:                                # %label_10
                                        # =>This Inner Loop Header: Depth=1
	movl	$.Lscanf_format.1, %edi
	movl	$a, %esi
	xorl	%eax, %eax
	callq	scanf
	movss	a(%rip), %xmm0          # xmm0 = mem[0],zero,zero,zero
	movss	s(%rip), %xmm1          # xmm1 = mem[0],zero,zero,zero
	addss	%xmm0, %xmm1
	movss	%xmm1, s(%rip)
	ucomiss	max(%rip), %xmm0
	jbe	.LBB0_4
# %bb.3:                                # %label_11
                                        #   in Loop: Header=BB0_2 Depth=1
	movss	a(%rip), %xmm0          # xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, max(%rip)
	jmp	.LBB0_1
	.p2align	4, 0x90
.LBB0_4:                                # %label_12
                                        #   in Loop: Header=BB0_2 Depth=1
	movss	min(%rip), %xmm0        # xmm0 = mem[0],zero,zero,zero
	ucomiss	a(%rip), %xmm0
	jbe	.LBB0_1
# %bb.5:                                # %label_17
                                        #   in Loop: Header=BB0_2 Depth=1
	movss	a(%rip), %xmm0          # xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, min(%rip)
.LBB0_1:                                # %for_cond
                                        #   in Loop: Header=BB0_2 Depth=1
	movl	i(%rip), %eax
	incl	%eax
	movl	%eax, i(%rip)
	cmpl	$10, %eax
	jle	.LBB0_2
# %bb.6:                                # %label_18
	movss	a(%rip), %xmm0          # xmm0 = mem[0],zero,zero,zero
	movl	$.Lprintf_format.2, %edi
	movb	$1, %al
	callq	printf
	xorl	%eax, %eax
	popq	%rcx
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	a,@object               # @a
	.comm	a,4,4
	.type	s,@object               # @s
	.comm	s,4,4
	.type	max,@object             # @max
	.comm	max,4,4
	.type	min,@object             # @min
	.comm	min,4,4
	.type	avg,@object             # @avg
	.comm	avg,4,4
	.type	i,@object               # @i
	.comm	i,4,4
	.type	.L__unnamed_1,@object   # @0
	.section	.rodata.str1.1,"aMS",@progbits,1
.L__unnamed_1:
	.asciz	"please input:"
	.size	.L__unnamed_1, 14

	.type	.Lprintf_format,@object # @printf_format
.Lprintf_format:
	.asciz	"%s"
	.size	.Lprintf_format, 3

	.type	.Lscanf_format,@object  # @scanf_format
.Lscanf_format:
	.asciz	"%lf"
	.size	.Lscanf_format, 4

	.type	.Lscanf_format.1,@object # @scanf_format.1
.Lscanf_format.1:
	.asciz	"%lf"
	.size	.Lscanf_format.1, 4

	.type	.Lprintf_format.2,@object # @printf_format.2
.Lprintf_format.2:
	.asciz	"%lf\n"
	.size	.Lprintf_format.2, 5


	.section	".note.GNU-stack","",@progbits
