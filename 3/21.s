	.text
	.globl _test
_test:
LFB0:
	leal	12(%rsi), %eax
	testw	%di, %di
	js	L5
	cmpw	$9, %si
	jle	L1
	movswl	%di, %eax
	movswl	%si, %esi
	cltd
	idivl	%esi
L1:
	ret
L5:
	cmpw	%di, %si
	jle	L3
	movl	%edi, %eax
	imull	%esi, %eax
	ret
L3:
	movl	%esi, %eax
	orl	%edi, %eax
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
