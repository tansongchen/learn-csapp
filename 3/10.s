	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	_arith3                         ## -- Begin function arith3
	.p2align	4, 0x90
_arith3:                                ## @arith3
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	orl	%esi, %edx
	sarl	$9, %edx
	notl	%edx
	subl	%esi, %edx
	movswl	%dx, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
