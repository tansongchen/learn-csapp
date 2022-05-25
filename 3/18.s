	.text
	.globl _test
_test:
LFB0:
	movq	%rdx, %rcx
	leaq	(%rsi,%rdx), %rax
	subq	%rdi, %rax
	cmpq	$5, %rdx
	jle	L2
	cmpq	$2, %rsi
	jle	L3
	movq	%rdi, %rax
	cqto
	idivq	%rcx
	ret
L3:
	movq	%rdi, %rax
	cqto
	idivq	%rsi
	ret
L2:
	cmpq	$2, %rdx
	jg	L1
	movq	%rdx, %rax
	cqto
	idivq	%rsi
L1:
	ret
LFE0:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x10
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB0-.
	.set L$set$2,LFE0-LFB0
	.quad L$set$2
	.uleb128 0
	.align 3
LEFDE1:
	.ident	"GCC: (Homebrew GCC 11.1.0_1) 11.1.0"
	.subsections_via_symbols
