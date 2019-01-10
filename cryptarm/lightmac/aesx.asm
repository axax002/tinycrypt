; Listing generated by Microsoft (R) Optimizing Compiler Version 19.12.25835.0 

	TITLE	c:\hub\cryptarm\lightmac\aesx.c
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMT
INCLUDELIB OLDNAMES

PUBLIC	_X
PUBLIC	_S
PUBLIC	_E
PUBLIC	_M
PUBLIC	_AE
EXTRN	_enc:PROC
EXTRN	_L:PROC
; Function compile flags: /Ogspy
; File c:\hub\cryptarm\lightmac\aesx.c
;	COMDAT _AE
_TEXT	SEGMENT
_s$ = -32						; size = 16
_t$ = -16						; size = 16
_c$ = 8							; size = 4
_e$ = 12						; size = 1
_AE	PROC						; COMDAT

; 112  : u8 AE(ctx*c,u8 e){

	push	ebp
	mov	ebp, esp
	sub	esp, 32					; 00000020H

; 113  :     u8 t[16],s[16],r=1;
; 114  :     if(e){

	cmp	BYTE PTR _e$[ebp], 0
	push	ebx
	push	esi
	mov	esi, DWORD PTR _c$[ebp]
	push	edi
	lea	edi, DWORD PTR [esi+32]
	je	SHORT $LN2@AE

; 115  :       r=enc(c->ek,s);

	lea	eax, DWORD PTR _s$[ebp]
	push	eax
	push	edi
	call	_enc
	mov	bl, al

; 116  :       L(c,t);

	lea	eax, DWORD PTR _t$[ebp]
	push	eax
	push	esi
	call	_L

; 117  :     }else{

	jmp	SHORT $LN5@AE
$LN2@AE:

; 118  :       L(c,t);

	lea	eax, DWORD PTR _t$[ebp]
	push	eax
	push	esi
	call	_L

; 119  :       r=enc(c->ek,s);

	lea	eax, DWORD PTR _s$[ebp]
	push	eax
	push	edi
	call	_enc
	mov	bl, al
$LN5@AE:
	add	esp, 16					; 00000010H

; 120  :     }
; 121  :     return r;

	mov	al, bl
	pop	edi
	pop	esi
	pop	ebx

; 122  : }

	mov	esp, ebp
	pop	ebp
	ret	0
_AE	ENDP
_TEXT	ENDS
; Function compile flags: /Ogspy
; File c:\hub\cryptarm\lightmac\aesx.c
;	COMDAT _M
_TEXT	SEGMENT
_s$1$ = -17						; size = 1
_m$ = -16						; size = 16
_l$1$ = 8						; size = 1
_c$ = 8							; size = 4
_t$ = 12						; size = 4
_M	PROC						; COMDAT

; 91   : void M(ctx*c,u8*t){

	sub	esp, 20					; 00000014H

; 92   :     u8 i,j,s,l=c->l,*p=c->b;
; 93   :     struct{u8 s;u8 b[15];}m;
; 94   : 
; 95   :     F(i,16)t[i]=0;

	xor	eax, eax

; 96   :     s=0;i=0;

	xor	dl, dl
	push	ebx
	push	ebp
	mov	ebp, DWORD PTR _c$[esp+24]
	push	esi
	mov	esi, DWORD PTR _t$[esp+28]
	push	edi
	mov	dh, BYTE PTR [ebp+48]
	lea	ebx, DWORD PTR [ebp+49]
	mov	edi, esi
	stosd
	stosd
	stosd
	stosd
	xor	ah, ah

; 97   :     while(l){

	test	dh, dh
	jmp	SHORT $LN31@M
$LL5@M:

; 98   :       m.b[i++]=*p++;

	mov	al, BYTE PTR [ebx]
	movzx	ecx, dl
	inc	dl
	inc	ebx
	mov	BYTE PTR _m$[esp+ecx+37], al

; 99   :       if(i==15){

	cmp	dl, 15					; 0000000fH
	jne	SHORT $LN13@M

; 100  :         s++;m.s=s;

	inc	ah
	mov	BYTE PTR _s$1$[esp+36], ah
	mov	BYTE PTR _m$[esp+36], ah

; 101  :         E(c->mk,(void*)&m);

	lea	eax, DWORD PTR _m$[esp+36]
	push	eax
	push	ebp
	call	_E
	pop	ecx
	pop	ecx
	lea	edx, DWORD PTR _m$[esp+37]
	mov	ecx, esi
	push	16					; 00000010H
	sub	edx, esi
	pop	edi
$LL9@M:

; 102  :         F(i,16)t[i]^=m.b[i];

	mov	al, BYTE PTR [edx+ecx]
	xor	BYTE PTR [ecx], al
	inc	ecx
	sub	edi, 1
	jne	SHORT $LL9@M

; 103  :         i=0;

	mov	ah, BYTE PTR _s$1$[esp+36]
	xor	dl, dl
	mov	dh, BYTE PTR _l$1$[esp+32]
$LN13@M:

; 104  :       }
; 105  :       l--;

	sub	dh, 1
$LN31@M:
	mov	BYTE PTR _l$1$[esp+32], dh

; 97   :     while(l){

	jne	SHORT $LL5@M

; 106  :     }
; 107  :     m.b[i++]=0x80;

	movzx	eax, dl
	mov	BYTE PTR _m$[esp+eax+37], 128		; 00000080H
	add	dl, 1

; 108  :     F(j,i)t[j]^=m.b[j];

	je	SHORT $LN11@M

; 106  :     }
; 107  :     m.b[i++]=0x80;

	lea	edi, DWORD PTR _m$[esp+37]
	movzx	edx, dl
	mov	ecx, esi
	sub	edi, esi
$LL12@M:

; 108  :     F(j,i)t[j]^=m.b[j];

	mov	al, BYTE PTR [ecx+edi]
	xor	BYTE PTR [ecx], al
	inc	ecx
	sub	edx, 1
	jne	SHORT $LL12@M
$LN11@M:

; 109  :     E(&c->mk[16],t);

	lea	eax, DWORD PTR [ebp+16]
	push	esi
	push	eax
	call	_E
	pop	ecx
	pop	ecx
	pop	edi
	pop	esi
	pop	ebp
	pop	ebx

; 110  : }

	add	esp, 20					; 00000014H
	ret	0
_M	ENDP
_TEXT	ENDS
; Function compile flags: /Ogspy
; File c:\hub\cryptarm\lightmac\aesx.c
;	COMDAT _E
_TEXT	SEGMENT
_r$1$ = -36						; size = 4
_k$ = -32						; size = 16
_v$ = -16						; size = 16
_ek$ = 8						; size = 4
_s$ = 12						; size = 4
_E	PROC						; COMDAT

; 69   :     u32 i,w,r=0;
; 70   :     u8  k[16],c=1;
; 71   :     union{u8 b[16];u32 w[4];}v;
; 72   : 
; 73   :     F(i,16)k[i]=ek[i],v.b[i]=s[i];

	mov	eax, DWORD PTR _s$[esp-4]
	sub	esp, 36					; 00000024H
	push	ebx
	push	ebp
	push	esi
	push	edi
	mov	esi, eax
	lea	edi, DWORD PTR _v$[esp+52]
	xor	ebp, ebp
	mov	bl, 1
	movsd
	movsd
	movsd
	movsd
	mov	esi, DWORD PTR _ek$[esp+48]
	lea	edi, DWORD PTR _k$[esp+52]
	movsd
	movsd
	movsd
	movsd
$LL5@E:

; 74   :     for(;;){
; 75   :       F(i,16)s[i]=v.b[i]^k[i];

	movups	xmm1, XMMWORD PTR _k$[esp+52]

; 76   :       if(++r>10)break;

	inc	ebp
	mov	DWORD PTR _r$1$[esp+52], ebp
	movups	xmm0, XMMWORD PTR _v$[esp+52]
	pxor	xmm1, xmm0
	movups	XMMWORD PTR [eax], xmm1
	cmp	ebp, 10					; 0000000aH
	ja	$LN34@E

; 77   :       k[0]^=c;c=X(c);

	xor	BYTE PTR _k$[esp+52], bl
	mov	al, bl

; 78   :       w=((u32*)&k)[3];

	mov	edi, DWORD PTR _k$[esp+64]
	add	bl, bl
	shr	al, 7
	movzx	eax, al
	imul	eax, eax, 27
	xor	bl, al
	xor	esi, esi
$LL13@E:

; 79   :       F(i,4)
; 80   :         w=R(w,8),k[i]^=S(w),k[i+4]^=k[i],
; 81   :         k[i+8]^=k[i+4],k[i+12]^=k[i+8];

	ror	edi, 8
	push	edi
	call	_S
	xor	BYTE PTR _k$[esp+esi+56], al
	mov	al, BYTE PTR _k$[esp+esi+56]
	xor	BYTE PTR _k$[esp+esi+60], al
	mov	al, BYTE PTR _k$[esp+esi+60]
	xor	BYTE PTR _k$[esp+esi+64], al
	mov	al, BYTE PTR _k$[esp+esi+64]
	xor	BYTE PTR _k$[esp+esi+68], al
	inc	esi
	pop	ecx
	cmp	esi, 4
	jb	SHORT $LL13@E

; 82   :       F(i,16)v.b[(i%4)+(((i/4)-(i%4))%4)*4]=S(s[i]);

	mov	ebp, DWORD PTR _s$[esp+48]
	xor	edi, edi
$LL16@E:
	movzx	eax, BYTE PTR [edi+ebp]
	mov	esi, edi
	push	eax
	and	esi, 3
	call	_S
	pop	ecx
	mov	ecx, edi
	shr	ecx, 2
	sub	ecx, esi
	and	ecx, 3
	inc	edi
	lea	ecx, DWORD PTR [esi+ecx*4]
	mov	BYTE PTR _v$[esp+ecx+52], al
	cmp	edi, 16					; 00000010H
	jb	SHORT $LL16@E

; 83   :       if(r!=10) {

	mov	ebp, DWORD PTR _r$1$[esp+52]
	mov	eax, DWORD PTR _s$[esp+48]
	cmp	ebp, 10					; 0000000aH
	je	$LL5@E

; 84   :         F(i,4)

	xor	ebp, ebp
$LL19@E:

; 85   :           w=v.w[i],

	mov	eax, DWORD PTR _v$[esp+ebp*4+52]
	mov	edi, eax
	ror	edi, 8
	mov	esi, eax
	mov	ecx, edi
	rol	esi, 16					; 00000010H
	xor	ecx, eax
	rol	eax, 8
	xor	esi, eax
	mov	edx, ecx
	and	edx, -2139062144			; 80808080H
	mov	eax, edx
	shr	edx, 7
	xor	eax, ecx
	add	eax, eax
	xor	esi, eax
	imul	eax, edx, 27
	xor	esi, eax
	xor	esi, edi
	mov	DWORD PTR _v$[esp+ebp*4+52], esi
	inc	ebp
	cmp	ebp, 4
	jb	SHORT $LL19@E

; 86   :           v.w[i]=R(w,8)^R(w,16)^R(w,24)^X(R(w,8)^w);
; 87   :       }
; 88   :     }

	mov	ebp, DWORD PTR _r$1$[esp+52]
	mov	eax, DWORD PTR _s$[esp+48]
	jmp	$LL5@E
$LN34@E:
	pop	edi

; 89   : }

	pop	esi
	pop	ebp
	pop	ebx
	add	esp, 36					; 00000024H
	ret	0
_E	ENDP
_TEXT	ENDS
; Function compile flags: /Ogspy
; File c:\hub\cryptarm\lightmac\aesx.c
;	COMDAT _S
_TEXT	SEGMENT
_x$ = 8							; size = 1
_S	PROC						; COMDAT

; 52   :     u8 i,z,y=x;

	mov	dl, BYTE PTR _x$[esp-4]

; 53   : 
; 54   :     if(x){

	test	dl, dl
	je	SHORT $LN6@S

; 55   :       for(i=1,y=1;i>0;i++){

	push	ebx
	mov	bl, 1
	mov	dh, bl
$LL4@S:

; 56   :         y^=X(y);

	mov	al, dh
	shr	al, 7
	movzx	eax, al
	imul	ecx, eax, 27
	mov	al, dh
	add	al, al
	xor	cl, al
	xor	dh, cl

; 57   :         if(y==x) break;

	cmp	dh, dl
	je	SHORT $LN21@S

; 55   :       for(i=1,y=1;i>0;i++){

	add	bl, 1
	jne	SHORT $LL4@S
$LN21@S:

; 58   :       }
; 59   :       x=~i;y=1;

	not	bl
	mov	dl, 1

; 60   :       F(i,x)

	test	bl, bl
	je	SHORT $LN31@S

; 58   :       }
; 59   :       x=~i;y=1;

	push	esi
	movzx	esi, bl
$LL7@S:

; 61   :         y^=X(y);

	mov	al, dl
	shr	al, 7
	movzx	eax, al
	imul	ecx, eax, 27
	mov	al, dl
	add	al, al
	xor	cl, al
	xor	dl, cl
	sub	esi, 1
	jne	SHORT $LL7@S
	pop	esi
$LN31@S:
	pop	ebx
$LN6@S:

; 62   :     }
; 63   :     z=y;

	push	4
	mov	al, dl
	pop	ecx
$LL10@S:

; 64   :     F(i,4)y=(y>>7)|(y<<1),z^= y;

	rol	dl, 1
	xor	al, dl
	sub	ecx, 1
	jne	SHORT $LL10@S

; 65   :     return z^0x63;

	xor	al, 99					; 00000063H

; 66   : }

	ret	0
_S	ENDP
_TEXT	ENDS
; Function compile flags: /Ogspy
; File c:\hub\cryptarm\lightmac\aesx.c
;	COMDAT _X
_TEXT	SEGMENT
_w$ = 8							; size = 4
_X	PROC						; COMDAT

; 47   :     u32 t=w&0x80808080;

	mov	ecx, DWORD PTR _w$[esp-4]
	and	ecx, -2139062144			; 80808080H

; 48   :     return ((w^t)<<1)^((t>>7)*0x1B);

	mov	eax, ecx
	shr	ecx, 7
	xor	eax, DWORD PTR _w$[esp-4]
	imul	ecx, ecx, 27
	add	eax, eax
	xor	eax, ecx

; 49   : }

	ret	0
_X	ENDP
_TEXT	ENDS
END