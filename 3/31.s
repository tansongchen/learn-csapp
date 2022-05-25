	.text
	.globl _switcher
_switcher:
LFB0:
	cmpq	$7, %rsi
	ja	L2
	leaq	L4(%rip), %r8
	movslq	(%r8,%rsi,4), %rax
	addq	%r8, %rax
	jmp	*%rax
	.p2align 2
L4:
	.long	L7-L4
	.long	L2-L4
	.long	L3-L4
	.long	L2-L4
	.long	L6-L4
	.long	L5-L4
	.long	L2-L4
	.long	L3-L4
L6:
	movq	%rsi, %rdi
	jmp	L2
L5:
	movq	%rdi, %rdx
	xorq	$15, %rdx
L7:
	leaq	112(%rdx), %rdi
L2:
	movq	%rdi, (%rcx)
	ret
L3:
	addq	%rdx, %rdi
	sarq	$2, %rdi
	jmp	L2
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
