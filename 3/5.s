	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_decode1                        ## -- Begin function decode1
	.p2align	4, 0x90
_decode1:                               ## @decode1
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	(%rdi), %rax
	movq	(%rsi), %rcx
	movq	(%rdx), %r8
	movq	%rax, (%rsi)
	movq	%rcx, (%rdx)
	movq	%r8, (%rdi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
