	.text
	.globl _get1
_get1:
LFB0:
	movq	(%rdi), %rax
	movq	%rax, (%rsi)
	ret
LFE0:
	.globl _get2
_get2:
LFB1:
	movzwl	8(%rdi), %eax
	movw	%ax, (%rsi)
	ret
LFE1:
	.globl _get3
_get3:
LFB2:
	addq	$10, %rdi
	movq	%rdi, (%rsi)
	ret
LFE2:
	.globl _get4
_get4:
LFB3:
	movq	%rdi, (%rsi)
	ret
LFE3:
	.globl _get5
_get5:
LFB4:
	movq	(%rdi), %rax
	movl	(%rdi,%rax,4), %eax
	movl	%eax, (%rsi)
	ret
LFE4:
	.globl _get6
_get6:
LFB5:
	movq	8(%rdi), %rax
	movzbl	(%rax), %eax
	movb	%al, (%rsi)
	ret
LFE5:
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
LSFDE3:
	.set L$set$3,LEFDE3-LASFDE3
	.long L$set$3
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB1-.
	.set L$set$4,LFE1-LFB1
	.quad L$set$4
	.uleb128 0
	.align 3
LEFDE3:
LSFDE5:
	.set L$set$5,LEFDE5-LASFDE5
	.long L$set$5
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB2-.
	.set L$set$6,LFE2-LFB2
	.quad L$set$6
	.uleb128 0
	.align 3
LEFDE5:
LSFDE7:
	.set L$set$7,LEFDE7-LASFDE7
	.long L$set$7
LASFDE7:
	.long	LASFDE7-EH_frame1
	.quad	LFB3-.
	.set L$set$8,LFE3-LFB3
	.quad L$set$8
	.uleb128 0
	.align 3
LEFDE7:
LSFDE9:
	.set L$set$9,LEFDE9-LASFDE9
	.long L$set$9
LASFDE9:
	.long	LASFDE9-EH_frame1
	.quad	LFB4-.
	.set L$set$10,LFE4-LFB4
	.quad L$set$10
	.uleb128 0
	.align 3
LEFDE9:
LSFDE11:
	.set L$set$11,LEFDE11-LASFDE11
	.long L$set$11
LASFDE11:
	.long	LASFDE11-EH_frame1
	.quad	LFB5-.
	.set L$set$12,LFE5-LFB5
	.quad L$set$12
	.uleb128 0
	.align 3
LEFDE11:
	.ident	"GCC: (Homebrew GCC 11.1.0_1) 11.1.0"
	.subsections_via_symbols
