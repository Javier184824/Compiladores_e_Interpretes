	.file	"constant_propagation_b_test.c"
	.intel_syntax noprefix
# GNU C23 (Ubuntu 15.2.0-16ubuntu1) version 15.2.0 (x86_64-linux-gnu)
#	compiled by GNU C version 15.2.0, GMP version 6.3.0, MPFR version 4.2.2, MPC version 1.3.1, isl version isl-0.27-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -masm=intel -mtune=generic -march=x86-64 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection -fzero-init-padding-bits=all
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64	
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp	#,
	.cfi_def_cfa_register 6
	mov	DWORD PTR -20[rbp], edi	# argc, argc
	mov	QWORD PTR -32[rbp], rsi	# argv, argv
# sources/constant_propagation_b_test.c:5:     x = 4;
	mov	DWORD PTR -8[rbp], 4	# x,
# sources/constant_propagation_b_test.c:6:     y = x + 2;
	mov	eax, DWORD PTR -8[rbp]	# tmp103, x
	add	eax, 2	# y_2,
	mov	DWORD PTR -4[rbp], eax	# y, y_2
# sources/constant_propagation_b_test.c:8:     x = 4;
	mov	DWORD PTR -8[rbp], 4	# x,
# sources/constant_propagation_b_test.c:9:     y = 6;
	mov	DWORD PTR -4[rbp], 6	# y,
# sources/constant_propagation_b_test.c:10:     return 0;
	mov	eax, 0	# _5,
# sources/constant_propagation_b_test.c:11: }
	pop	rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
