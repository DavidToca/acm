int main()
{
__asm__ __volatile__(
"	jmp	_main2\n"
"	.p2align 4,,15\n"
"_find:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%ebx\n"
"	movl	8(%ebp), %ebx\n"
"	movl	_root, %ecx\n"
"	.p2align 4,,15\n"
"L10:\n"
"	movl	_left(,%ecx,4), %edx\n"
"	movl	_count(,%edx,4), %eax\n"
"	cmpl	%eax, %ebx\n"
"	jge	L5\n"
"	movl	%edx, %ecx\n"
"	jmp	L10\n"
"	.p2align 4,,7\n"
"L5:\n"
"	je	L9\n"
"	subl	%eax, %ebx\n"
"	leal	-1(%ebx), %ebx\n"
"	movl	_right(,%ecx,4), %ecx\n"
"	jmp	L10\n"
"L9:\n"
"	movl	_key(,%ecx,4), %eax\n"
"	popl	%ebx\n"
"	popl	%ebp\n"
"	ret\n"
"	.p2align 4,,15\n"
"_rem:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%edi\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	movl	8(%ebp), %ebx\n"
"	movl	_root, %ecx\n"
"	xorl	%edi, %edi\n"
"	.p2align 4,,15\n"
"L41:\n"
"	decl	_count(,%ecx,4)\n"
"	movl	_left(,%ecx,4), %edx\n"
"	movl	_count(,%edx,4), %eax\n"
"	cmpl	%eax, %ebx\n"
"	je	L13\n"
"	movl	%ecx, %edi\n"
"	jge	L16\n"
"	movl	%edx, %ecx\n"
"	jmp	L41\n"
"	.p2align 4,,7\n"
"L16:\n"
"	subl	%eax, %ebx\n"
"	leal	-1(%ebx), %ebx\n"
"	movl	_right(,%ecx,4), %ecx\n"
"	jmp	L41\n"
"L13:\n"
"	testl	%edx, %edx\n"
"	je	L18\n"
"	movl	_right(,%ecx,4), %ebx\n"
"	testl	%ebx, %ebx\n"
"	je	L18\n"
"	movl	_count(,%edx,4), %eax\n"
"	cmpl	%eax, _count(,%ebx,4)\n"
"	jl	L19\n"
"	movl	%ecx, %edi\n"
"	movl	%ebx, %edx\n"
"	movl	_left(,%ebx,4), %eax\n"
"	testl	%eax, %eax\n"
"	je	L25\n"
"L24:\n"
"	decl	_count(,%edx,4)\n"
"	movl	%edx, %edi\n"
"	movl	%eax, %edx\n"
"	movl	_left(,%eax,4), %eax\n"
"	testl	%eax, %eax\n"
"	jne	L24\n"
"L25:\n"
"	movl	_key(,%edx,4), %eax\n"
"	movl	%eax, _key(,%ecx,4)\n"
"	movl	%edx, %ecx\n"
"	movl	_left(,%edx,4), %edx\n"
"L18:\n"
"	testl	%edx, %edx\n"
"	jne	L31\n"
"	movl	_right(,%ecx,4), %ebx\n"
"	testl	%ebx, %ebx\n"
"	jne	L31\n"
"	cmpl	%ecx, _left(,%edi,4)\n"
"	je	L43\n"
"	xorl	%eax, %eax\n"
"	movl	%eax, _right(,%edi,4)\n"
"L11:\n"
"	popl	%ebx\n"
"	popl	%esi\n"
"	popl	%edi\n"
"	popl	%ebp\n"
"	ret\n"
"L43:\n"
"	xorl	%edx, %edx\n"
"L42:\n"
"	movl	%edx, _left(,%edi,4)\n"
"	jmp	L11\n"
"L31:\n"
"	testl	%edx, %edx\n"
"	jne	L34\n"
"	movl	_right(,%ecx,4), %edx\n"
"L34:\n"
"	testl	%edi, %edi\n"
"	jne	L35\n"
"	movl	%edx, _root\n"
"	jmp	L11\n"
"L35:\n"
"	cmpl	%ecx, _left(,%edi,4)\n"
"	je	L42\n"
"	movl	%edx, _right(,%edi,4)\n"
"	jmp	L11\n"
"L19:\n"
"	movl	%ecx, %edi\n"
"	movl	_right(,%edx,4), %eax\n"
"	testl	%eax, %eax\n"
"	je	L25\n"
"L30:\n"
"	decl	_count(,%edx,4)\n"
"	movl	%edx, %edi\n"
"	movl	%eax, %edx\n"
"	movl	_right(,%eax,4), %eax\n"
"	testl	%eax, %eax\n"
"	jne	L30\n"
"	jmp	L25\n"
"	.p2align 4,,15\n"
"_build:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	subl	$20, %esp\n"
"	movl	%ebx, -12(%ebp)\n"
"	movl	%esi, -8(%ebp)\n"
"	movl	%edi, -4(%ebp)\n"
"	movl	8(%ebp), %edx\n"
"	movl	12(%ebp), %edi\n"
"	cmpl	%edi, %edx\n"
"	je	L51\n"
"	leal	(%edi,%edx), %esi\n"
"	sarl	%esi\n"
"	xorl	%eax, %eax\n"
"	cmpl	%esi, %edx\n"
"	jl	L52\n"
"L48:\n"
"	movl	_last, %ebx\n"
"	incl	%ebx\n"
"	movl	%ebx, _last\n"
"	movl	%eax, _left(,%ebx,4)\n"
"	incl	%esi\n"
"	cmpl	%edi, %esi\n"
"	jle	L53\n"
"L49:\n"
"	movl	_left(,%ebx,4), %edx\n"
"	movl	_right(,%ebx,4), %eax\n"
"	movl	_count(,%eax,4), %eax\n"
"	movl	_count(,%edx,4), %esi\n"
"	addl	%esi, %eax\n"
"	incl	%eax\n"
"	movl	%eax, _count(,%ebx,4)\n"
"	movl	%ebx, %eax\n"
"L44:\n"
"	movl	-12(%ebp), %ebx\n"
"	movl	-8(%ebp), %esi\n"
"	movl	-4(%ebp), %edi\n"
"	movl	%ebp, %esp\n"
"	popl	%ebp\n"
"	ret\n"
"	.p2align 4,,7\n"
"L53:\n"
"	movl	%edi, 4(%esp)\n"
"	movl	%esi, (%esp)\n"
"	call	_build\n"
"	movl	%eax, _right(,%ebx,4)\n"
"	jmp	L49\n"
"	.p2align 4,,7\n"
"L52:\n"
"	leal	-1(%esi), %eax\n"
"	movl	%eax, 4(%esp)\n"
"	movl	%edx, (%esp)\n"
"	call	_build\n"
"	jmp	L48\n"
"	.p2align 4,,7\n"
"L51:\n"
"	movl	_last, %eax\n"
"	incl	%eax\n"
"	movl	%eax, _last\n"
"	movl	$1, %edi\n"
"	movl	%edi, _count(,%eax,4)\n"
"	jmp	L44\n"
"	.p2align 4,,15\n"
"_rec:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	subl	$4, %esp\n"
"	movl	8(%ebp), %ebx\n"
"	testl	%ebx, %ebx\n"
"	je	L62\n"
"	movl	$1, %esi\n"
"	.p2align 4,,15\n"
"L60:\n"
"	movl	_key(,%ebx,4), %ecx\n"
"	movl	%ecx, %eax\n"
"	sarl	$5, %eax\n"
"	andl	$31, %ecx\n"
"	movl	%esi, %edx\n"
"	sall	%cl, %edx\n"
"	orl	%edx, _map(,%eax,4)\n"
"	movl	_left(,%ebx,4), %eax\n"
"	movl	%eax, (%esp)\n"
"	call	_rec\n"
"	movl	_right(,%ebx,4), %ebx\n"
"	testl	%ebx, %ebx\n"
"	jne	L60\n"
"L62:\n"
"	popl	%eax\n"
"	popl	%ebx\n"
"	popl	%esi\n"
"	popl	%ebp\n"
"	ret\n"
"	.data\n"
"	.align 32\n"
"_p.0:\n"
"	.long	1\n"
"	.long	3\n"
"	.long	7\n"
"	.long	9\n"
"	.long	13\n"
"	.long	15\n"
"	.long	21\n"
"	.long	25\n"
"	.long	31\n"
"	.long	33\n"
"	.long	37\n"
"	.long	43\n"
"	.long	45\n"
"	.long	49\n"
"	.long	51\n"
"	.long	55\n"
"	.long	63\n"
"	.long	67\n"
"	.long	69\n"
"	.long	73\n"
"	.long	75\n"
"	.long	79\n"
"	.long	85\n"
"	.long	87\n"
"	.long	93\n"
"	.long	97\n"
"	.long	99\n"
"	.long	105\n"
"	.long	109\n"
"	.long	111\n"
"	.long	115\n"
"	.long	117\n"
"	.long	127\n"
"	.long	129\n"
"	.long	133\n"
"	.long	135\n"
"	.long	139\n"
"	.long	141\n"
"	.long	147\n"
"	.long	151\n"
"	.long	157\n"
"	.long	159\n"
"	.long	163\n"
"	.long	169\n"
"	.long	171\n"
"	.long	175\n"
"	.long	177\n"
"	.long	181\n"
"	.long	189\n"
"	.long	193\n"
"	.long	195\n"
"	.long	199\n"
"	.long	201\n"
"	.long	205\n"
"	.long	211\n"
"	.long	213\n"
"	.long	219\n"
"	.long	223\n"
"	.long	225\n"
"	.long	231\n"
"	.long	235\n"
"	.long	237\n"
"	.long	241\n"
"	.long	243\n"
"	.text\n"
"	.p2align 4,,15\n"
"_make:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%edi\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	subl	$12, %esp\n"
"	xorl	%esi, %esi\n"
"	movl	%esi, _last\n"
"	xorl	%ebx, %ebx\n"
"	movl	%ebx, _count\n"
"	movl	$254234, %ecx\n"
"	movl	%ecx, 4(%esp)\n"
"	movl	$0, (%esp)\n"
"	call	_build\n"
"	movl	%eax, _root\n"
"	movl	$1, %ebx\n"
"	xorl	%edi, %edi\n"
"L73:\n"
"	xorl	%esi, %esi\n"
"	.p2align 4,,15\n"
"L72:\n"
"	movl	%edi, %eax\n"
"	movl	_p.0(,%esi,4), %edx\n"
"	addl	%edx, %eax\n"
"	movl	%eax, _key(,%ebx,4)\n"
"	incl	%ebx\n"
"	incl	%esi\n"
"	cmpl	$63, %esi\n"
"	jle	L72\n"
"	addl	$252, %edi\n"
"	cmpl	$254260, %ebx\n"
"	jle	L73\n"
"	movl	$4, %esi\n"
"L74:\n"
"	movl	%esi, (%esp)\n"
"	call	_find\n"
"	leal	-1(%eax), %edi\n"
"	movl	_root, %eax\n"
"	cmpl	_count(,%eax,4), %edi\n"
"	jge	L75\n"
"	movl	%edi, %ebx\n"
"	.p2align 4,,15\n"
"L82:\n"
"	movl	%ebx, (%esp)\n"
"	call	_rem\n"
"	addl	%edi, %ebx\n"
"	movl	_root, %eax\n"
"	cmpl	_count(,%eax,4), %ebx\n"
"	jl	L82\n"
"	incl	%esi\n"
"	jmp	L74\n"
"L75:\n"
"	movl	%eax, (%esp)\n"
"	call	_rec\n"
"	addl	$12, %esp\n"
"	popl	%ebx\n"
"	popl	%esi\n"
"	popl	%edi\n"
"	popl	%ebp\n"
"	ret\n"
"	.p2align 4,,15\n"
"_sol:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%ebx\n"
"	movl	8(%ebp), %ebx\n"
"	cmpl	$1, %ebx\n"
"	jle	L91\n"
"	testb	$1, %bl\n"
"	je	L90\n"
"L91:\n"
"	movl	$-1, %ecx\n"
"L89:\n"
"	movl	%ecx, %eax\n"
"	popl	%ebx\n"
"	popl	%ebp\n"
"	ret\n"
"L90:\n"
"	movl	%ebx, %edx\n"
"	sarl	%edx\n"
"	testl	%edx, %edx\n"
"	jle	L97\n"
"	movl	%ebx, %eax\n"
"	sarl	$6, %eax\n"
"	movl	%edx, %ecx\n"
"	andl	$31, %ecx\n"
"	movl	_map(,%eax,4), %eax\n"
"	shrl	%cl, %eax\n"
"	testb	$1, %al\n"
"	jne	L97\n"
"	.p2align 4,,15\n"
"L96:\n"
"	decl	%edx\n"
"	testl	%edx, %edx\n"
"	jle	L97\n"
"	movl	%edx, %eax\n"
"	sarl	$5, %eax\n"
"	movl	%edx, %ecx\n"
"	andl	$31, %ecx\n"
"	movl	_map(,%eax,4), %eax\n"
"	shrl	%cl, %eax\n"
"	testb	$1, %al\n"
"	je	L96\n"
"	.p2align 4,,15\n"
"L97:\n"
"	movl	%edx, %eax\n"
"	sarl	$5, %eax\n"
"	movl	%edx, %ecx\n"
"	andl	$31, %ecx\n"
"	movl	_map(,%eax,4), %eax\n"
"	shrl	%cl, %eax\n"
"	testb	$1, %al\n"
"	je	L99\n"
"	movl	%ebx, %ecx\n"
"	subl	%edx, %ecx\n"
"	movl	%ecx, %eax\n"
"	sarl	$5, %eax\n"
"	andl	$31, %ecx\n"
"	movl	_map(,%eax,4), %eax\n"
"	shrl	%cl, %eax\n"
"	movl	%edx, %ecx\n"
"	testb	$1, %al\n"
"	jne	L89\n"
"L99:\n"
"	subl	$2, %edx\n"
"	jmp	L97\n"
"LC1:\n"
"	.ascii \" is the sum of \\0\"\n"
"	.align 32\n"
"LC0:\n"
"	.ascii \" is not the sum of two luckies!\\12\\0\"\n"
"	.p2align 4,,15\n"
"_main2:\n"
"	pushl	%ebp\n"
"	movl	%esp, %ebp\n"
"	pushl	%edi\n"
"	pushl	%esi\n"
"	pushl	%ebx\n"
"	subl	$44, %esp\n"
"	movl	$48, -24(%ebp)\n"
"	.p2align 4,,15\n"
"L109:\n"
"	movl	-24(%ebp), %eax\n"
"	movl	$1, %ecx\n"
"	movl	%ecx, _isdigx.5(,%eax,4)\n"
"	movl	$1, %edx\n"
"	movl	%edx, _isdig.4(,%eax,4)\n"
"	incl	%eax\n"
"	movl	%eax, -24(%ebp)\n"
"	cmpl	$57, %eax\n"
"	jle	L109\n"
"	movl	$1, %eax\n"
"	movl	%eax, _isdigx.5\n"
"	movl	$1048576, %edi\n"
"	movl	%edi, 8(%esp)\n"
"	movl	$_inbuf.1, -20(%ebp)\n"
"	movl	$_inbuf.1, %esi\n"
"	movl	%esi, 4(%esp)\n"
"	movl	$0, (%esp)\n"
"	call	read\n"
"	movb	$0, _inbuf.1(%eax)\n"
"	movl	$_outbuf.2, %esi\n"
"	call	_make\n"
"	.p2align 4,,15\n"
"L184:\n"
"	movl	-20(%ebp), %eax\n"
"	movzbl	(%eax), %edx\n"
"	movsbl	%dl,%eax\n"
"	movl	_isdigx.5(,%eax,4), %ebx\n"
"	testl	%ebx, %ebx\n"
"	jne	L165\n"
"	.p2align 4,,15\n"
"L116:\n"
"	incl	-20(%ebp)\n"
"	movl	-20(%ebp), %eax\n"
"	movzbl	(%eax), %edx\n"
"	movsbl	%dl,%eax\n"
"	movl	_isdigx.5(,%eax,4), %ecx\n"
"	testl	%ecx, %ecx\n"
"	je	L116\n"
"L165:\n"
"	testb	%dl, %dl\n"
"	je	L111\n"
"	movsbl	%dl,%eax\n"
"	leal	-48(%eax), %edi\n"
"	incl	-20(%ebp)\n"
"	movl	-20(%ebp), %edx\n"
"	movsbl	(%edx),%eax\n"
"	movl	_isdig.4(,%eax,4), %edx\n"
"	testl	%edx, %edx\n"
"	je	L167\n"
"	movl	%eax, %edx\n"
"	.p2align 4,,15\n"
"L122:\n"
"	leal	(%edi,%edi,4), %eax\n"
"	leal	-48(%edx,%eax,2), %edi\n"
"	incl	-20(%ebp)\n"
"	movl	-20(%ebp), %edx\n"
"	movsbl	(%edx),%eax\n"
"	movl	%eax, %edx\n"
"	movl	_isdig.4(,%eax,4), %eax\n"
"	testl	%eax, %eax\n"
"	jne	L122\n"
"L167:\n"
"	movl	%edi, (%esp)\n"
"	call	_sol\n"
"	movl	%eax, -24(%ebp)\n"
"	movl	%edi, %ecx\n"
"	movl	$_tmp.3, %ebx\n"
"	testl	%edi, %edi\n"
"	jle	L169\n"
"	.p2align 4,,15\n"
"L127:\n"
"	movl	$1717986919, %eax\n"
"	imull	%ecx\n"
"	movl	%eax, -32(%ebp)\n"
"	movl	%edx, -28(%ebp)\n"
"	movl	-28(%ebp), %edx\n"
"	sarl	$2, %edx\n"
"	movl	%ecx, %eax\n"
"	sarl	$31, %eax\n"
"	subl	%eax, %edx\n"
"	leal	(%edx,%edx,4), %eax\n"
"	addl	%eax, %eax\n"
"	subl	%eax, %ecx\n"
"	movb	%cl, %al\n"
"	addb	$48, %al\n"
"	movb	%al, (%ebx)\n"
"	incl	%ebx\n"
"	movl	%edx, %ecx\n"
"	testl	%edx, %edx\n"
"	jg	L127\n"
"L169:\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.3-1, %ebx\n"
"	jbe	L171\n"
"	.p2align 4,,15\n"
"L131:\n"
"	movzbl	(%ebx), %eax\n"
"	movb	%al, (%esi)\n"
"	incl	%esi\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.3-1, %ebx\n"
"	ja	L131\n"
"L171:\n"
"	movl	-24(%ebp), %eax\n"
"	testl	%eax, %eax\n"
"	js	L185\n"
"	movl	$LC1, %ebx\n"
"	movzbl	LC1, %eax\n"
"	testb	%al, %al\n"
"	je	L175\n"
"	.p2align 4,,15\n"
"L143:\n"
"	incl	%ebx\n"
"	movb	%al, (%esi)\n"
"	incl	%esi\n"
"	movzbl	(%ebx), %eax\n"
"	testb	%al, %al\n"
"	jne	L143\n"
"L175:\n"
"	movl	-24(%ebp), %ecx\n"
"	movl	$_tmp.3, %ebx\n"
"	testl	%ecx, %ecx\n"
"	jle	L177\n"
"	.p2align 4,,15\n"
"L148:\n"
"	movl	$1717986919, %eax\n"
"	imull	%ecx\n"
"	sarl	$2, %edx\n"
"	movl	%ecx, %eax\n"
"	sarl	$31, %eax\n"
"	subl	%eax, %edx\n"
"	leal	(%edx,%edx,4), %eax\n"
"	addl	%eax, %eax\n"
"	subl	%eax, %ecx\n"
"	movb	%cl, %al\n"
"	addb	$48, %al\n"
"	movb	%al, (%ebx)\n"
"	incl	%ebx\n"
"	movl	%edx, %ecx\n"
"	testl	%edx, %edx\n"
"	jg	L148\n"
"L177:\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.3-1, %ebx\n"
"	jbe	L179\n"
"	.p2align 4,,15\n"
"L152:\n"
"	movzbl	(%ebx), %eax\n"
"	movb	%al, (%esi)\n"
"	incl	%esi\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.3-1, %ebx\n"
"	ja	L152\n"
"L179:\n"
"	movb	$32, (%esi)\n"
"	incl	%esi\n"
"	movb	$97, (%esi)\n"
"	incl	%esi\n"
"	movb	$110, (%esi)\n"
"	incl	%esi\n"
"	movb	$100, (%esi)\n"
"	incl	%esi\n"
"	movb	$32, (%esi)\n"
"	incl	%esi\n"
"	movl	%edi, %ecx\n"
"	movl	-24(%ebp), %eax\n"
"	subl	%eax, %ecx\n"
"	movl	$_tmp.3, %ebx\n"
"	testl	%ecx, %ecx\n"
"	jle	L181\n"
"	movl	$1717986919, %edi\n"
"	.p2align 4,,15\n"
"L157:\n"
"	movl	%ecx, %eax\n"
"	imull	%edi\n"
"	sarl	$2, %edx\n"
"	movl	%ecx, %eax\n"
"	sarl	$31, %eax\n"
"	subl	%eax, %edx\n"
"	leal	(%edx,%edx,4), %eax\n"
"	addl	%eax, %eax\n"
"	subl	%eax, %ecx\n"
"	movb	%cl, %al\n"
"	addb	$48, %al\n"
"	movb	%al, (%ebx)\n"
"	incl	%ebx\n"
"	movl	%edx, %ecx\n"
"	testl	%edx, %edx\n"
"	jg	L157\n"
"L181:\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.3-1, %ebx\n"
"	jbe	L183\n"
"	.p2align 4,,15\n"
"L161:\n"
"	movzbl	(%ebx), %eax\n"
"	movb	%al, (%esi)\n"
"	incl	%esi\n"
"	decl	%ebx\n"
"	cmpl	$_tmp.3-1, %ebx\n"
"	ja	L161\n"
"L183:\n"
"	movb	$46, (%esi)\n"
"	incl	%esi\n"
"	movb	$10, (%esi)\n"
"	incl	%esi\n"
"	jmp	L184\n"
"L185:\n"
"	movl	$LC0, %ebx\n"
"	movzbl	LC0, %eax\n"
"	testb	%al, %al\n"
"	je	L184\n"
"	.p2align 4,,15\n"
"L137:\n"
"	incl	%ebx\n"
"	movb	%al, (%esi)\n"
"	incl	%esi\n"
"	movzbl	(%ebx), %eax\n"
"	testb	%al, %al\n"
"	jne	L137\n"
"	jmp	L184\n"
"L111:\n"
"	subl	$_outbuf.2, %esi\n"
"	movl	%esi, 8(%esp)\n"
"	movl	$_outbuf.2, %edi\n"
"	movl	%edi, 4(%esp)\n"
"	movl	$1, (%esp)\n"
"	call	write\n"
"	movl	$0, (%esp)\n"
"	call	exit\n"
".lcomm _last,16\n"
".lcomm _root,16\n"
".lcomm _tmp.3,256\n"
".lcomm _isdig.4,1024\n"
".lcomm _isdigx.5,1024\n"
".lcomm _map,262144\n"
".lcomm _left,1018000\n"
".lcomm _right,1018000\n"
".lcomm _key,1018000\n"
".lcomm _count,1018000\n"
".lcomm _inbuf.1,1048576\n"
".lcomm _outbuf.2,4194304\n"
);
}
