; Listing generated by Microsoft (R) Optimizing Compiler Version 19.13.26128.0 

	TITLE	C:\hub\cryptarm\cubehash\t2.c
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMT
INCLUDELIB OLDNAMES

PUBLIC	_P
PUBLIC	_cubehash
EXTRN	_memcpy:PROC
EXTRN	_memset:PROC
; Function compile flags: /Ogspy
; File c:\hub\cryptarm\cubehash\t2.c
;	COMDAT _cubehash
_TEXT	SEGMENT
_x$ = -128						; size = 128
_l$ = 8							; size = 4
_in$ = 12						; size = 4
_out$ = 16						; size = 4
_cubehash PROC						; COMDAT

; 50   : void cubehash(W l,void*in,void*out){

	push	ebp
	mov	ebp, esp
	sub	esp, 128				; 00000080H
	push	esi

; 51   :   W i;B x[128];
; 52   : 
; 53   :   F(128)x[i]=0;*x=32;x[4]=x[8]=1;P(x,10);

	push	128					; 00000080H
	xor	esi, esi
	lea	eax, DWORD PTR _x$[ebp]
	push	esi
	push	eax
	call	_memset
	lea	eax, DWORD PTR _x$[ebp]
	mov	BYTE PTR _x$[ebp], 32			; 00000020H
	push	10					; 0000000aH
	push	eax
	mov	BYTE PTR _x$[ebp+8], 1
	mov	BYTE PTR _x$[ebp+4], 1
	call	_P
	add	esp, 20					; 00000014H

; 54   :   F(l)*x^=((B*)in)[i],P(x,1);

	cmp	DWORD PTR _l$[ebp], esi
	jbe	SHORT $LN6@cubehash
	push	edi
	mov	edi, DWORD PTR _in$[ebp]
$LL7@cubehash:
	mov	al, BYTE PTR [esi+edi]
	xor	BYTE PTR _x$[ebp], al
	lea	eax, DWORD PTR _x$[ebp]
	push	1
	push	eax
	call	_P
	inc	esi
	pop	ecx
	pop	ecx
	cmp	esi, DWORD PTR _l$[ebp]
	jb	SHORT $LL7@cubehash
	pop	edi
$LN6@cubehash:

; 55   :   *x^=128;P(x,1);

	xor	BYTE PTR _x$[ebp], 128			; 00000080H
	lea	eax, DWORD PTR _x$[ebp]
	push	1
	push	eax
	call	_P

; 56   :   x[124]^=1;P(x,10);

	xor	BYTE PTR _x$[ebp+124], 1
	lea	eax, DWORD PTR _x$[ebp]
	push	10					; 0000000aH
	push	eax
	call	_P

; 57   :   F(32)((B*)out)[i]=x[i];

	push	32					; 00000020H
	lea	eax, DWORD PTR _x$[ebp]
	push	eax
	push	DWORD PTR _out$[ebp]
	call	_memcpy
	add	esp, 28					; 0000001cH
	pop	esi

; 58   : }

	mov	esp, ebp
	pop	ebp
	ret	0
_cubehash ENDP
_TEXT	ENDS
; Function compile flags: /Ogspy
; File c:\hub\cryptarm\cubehash\t2.c
;	COMDAT _P
_TEXT	SEGMENT
_j$1$ = -76						; size = 4
tv876 = -72						; size = 4
tv879 = -68						; size = 4
_y$ = -64						; size = 64
_k$1$ = 8						; size = 4
_b$ = 8							; size = 4
_n$ = 12						; size = 4
_P	PROC						; COMDAT

; 36   : void P(void*b, W n){

	sub	esp, 76					; 0000004cH
	push	ebx

; 37   :   W i,j,k,y[16],*x=b;
; 38   :   
; 39   :   while(n--){

	mov	ebx, DWORD PTR _n$[esp+76]
	test	ebx, ebx
	je	$LN41@P
	push	ebp
	mov	ebp, DWORD PTR _b$[esp+80]
	push	esi
	push	edi
	lea	edi, DWORD PTR _y$[esp+92]
	sub	edi, ebp
	mov	DWORD PTR tv879[esp+92], edi
$LL2@P:
	dec	ebx

; 40   :     for(k=7,j=2;j>0;k+=4,j--){

	mov	DWORD PTR _k$1$[esp+88], 7
	push	8
	pop	esi
	mov	DWORD PTR _n$[esp+88], ebx
	lea	ebx, DWORD PTR [ebp+64]
	mov	DWORD PTR _j$1$[esp+92], 2
	mov	DWORD PTR tv876[esp+92], esi
$LL6@P:

; 41   :       F(16)x[i+16]+=x[i];

	push	4
	mov	eax, ebx
	pop	ecx
$LL9@P:
	movups	xmm0, XMMWORD PTR [eax]
	movups	xmm1, XMMWORD PTR [eax-64]
	paddd	xmm1, xmm0
	movups	XMMWORD PTR [eax], xmm1
	lea	eax, DWORD PTR [eax+16]
	sub	ecx, 1
	jne	SHORT $LL9@P

; 42   :       F(16)y[i^(j*4)]=x[i];

	xor	edx, edx
$LL12@P:
	mov	eax, DWORD PTR [ebp+edx*4]
	mov	ecx, esi
	xor	ecx, edx
	inc	edx
	mov	DWORD PTR _y$[esp+ecx*4+92], eax
	cmp	edx, 16					; 00000010H
	jb	SHORT $LL12@P

; 43   :       F(16)x[i]=R(y[i],k);

	mov	ecx, DWORD PTR _k$1$[esp+88]
	mov	edx, ebp
	push	16					; 00000010H
	pop	esi
$LL15@P:
	mov	eax, DWORD PTR [edi+edx]
	rol	eax, cl
	mov	DWORD PTR [edx], eax
	lea	edx, DWORD PTR [edx+4]
	sub	esi, 1
	jne	SHORT $LL15@P

; 44   :       F(16)x[i]^=x[i+16];

	xor	eax, eax
$LL18@P:
	movups	xmm0, XMMWORD PTR [ebp+eax*4]
	movups	xmm1, XMMWORD PTR [ebx+eax*4]
	pxor	xmm1, xmm0
	movups	XMMWORD PTR [ebp+eax*4], xmm1
	add	eax, 4
	cmp	eax, 16					; 00000010H
	jb	SHORT $LL18@P

; 45   :       F(16)y[i^j]=x[i+16];

	mov	edi, DWORD PTR _j$1$[esp+92]
	xor	edx, edx
	mov	esi, ebx
$LL21@P:
	mov	eax, DWORD PTR [esi]
	mov	ecx, edx
	xor	ecx, edi
	lea	esi, DWORD PTR [esi+4]
	inc	edx
	mov	DWORD PTR _y$[esp+ecx*4+92], eax
	cmp	edx, 16					; 00000010H
	jb	SHORT $LL21@P

; 46   :       F(16)x[i+16]=y[i];

	add	DWORD PTR _k$1$[esp+88], 4
	lea	esi, DWORD PTR _y$[esp+92]
	dec	DWORD PTR _j$1$[esp+92]
	mov	edi, ebx
	push	16					; 00000010H
	pop	ecx
	rep movsd
	mov	esi, DWORD PTR tv876[esp+92]
	mov	edi, DWORD PTR tv879[esp+92]
	sub	esi, 4
	mov	DWORD PTR tv876[esp+92], esi
	jne	$LL6@P

; 37   :   W i,j,k,y[16],*x=b;
; 38   :   
; 39   :   while(n--){

	mov	ebx, DWORD PTR _n$[esp+88]
	test	ebx, ebx
	jne	$LL2@P
	pop	edi
	pop	esi
	pop	ebp
$LN41@P:
	pop	ebx

; 47   :     }
; 48   :   }
; 49   : }

	add	esp, 76					; 0000004cH
	ret	0
_P	ENDP
_TEXT	ENDS
END
