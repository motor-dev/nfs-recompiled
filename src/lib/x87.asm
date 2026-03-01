global convert80x64
global convert80x32
global convert64x80
global convert32x80
global convert80xi64
global convert80xi32
global convert80xi16
global converti16x80
global converti32x80
global converti64x80
global chs80
global add80
global sub80
global mul80
global div80
global log280
global sin80
global cos80
global sqrt80
global tan80
global abs80
global atan80
global cmp80
global round80
global f2xm180
global scale80
global rem80

section .text

convert80x64:
    fld  tword [rdi]
    fstp qword [rsi]
    ret

convert80x32:
    fld  tword [rdi]
    fstp dword [rsi]
    ret

convert64x80:
    fld  qword [rdi]
    fstp tword [rsi]
    ret

convert32x80:
    fld  dword [rdi]
    fstp tword [rsi]
    ret

convert80xi64:
    fld   tword [rdi]
    fistp qword [rsi]
    ret

convert80xi32:
    fld   tword [rdi]
    fistp dword [rsi]
    ret

convert80xi16:
    fld   tword [rdi]
    fistp word [rsi]
    ret

converti16x80:
    fild word [rdi]
    fstp tword [rsi]
    ret

converti32x80:
    fild dword [rdi]
    fstp tword [rsi]
    ret

converti64x80:
    fild qword [rdi]
    fstp tword [rsi]
    ret

chs80:
    fld  tword [rdi]
    xor rax, rax
    fchs
    fstsw ax
    fstp tword [rdi]
    ret

add80:
    fld  tword [rsi]
    xor rax, rax
    fld  tword [rdi]
    faddp
    fstsw ax
    fstp tword [rdi]
    ret

sub80:
    fld  tword [rdi]
    xor rax, rax
    fld  tword [rsi]
    fsubp
    fstsw ax
    fstp tword [rdi]
    ret

mul80:
    fld  tword [rdi]
    xor rax, rax
    fld  tword [rsi]
    fmulp
    fstsw ax
    fstp tword [rdi]
    ret

div80:
    fld  tword [rdi]
    xor rax, rax
    fld  tword [rsi]
    fdivp
    fstsw ax
    fstp tword [rdi]
    ret

sin80:
    fld  tword [rdi]
    xor rax, rax
    fsin
    fstsw ax
    fstp tword [rdi]
    ret

log280:
    fld1
    fld  tword [rdi]
    xor rax, rax
    fyl2x
    fstsw ax
    fstp tword [rdi]
    ret

cos80:
    fld  tword [rdi]
    xor rax, rax
    fcos
    fstsw ax
    fstp tword [rdi]
    ret

sqrt80:
    fld  tword [rdi]
    xor rax, rax
    fsqrt
    fstsw ax
    fstp tword [rdi]
    ret

tan80:
    fld  tword [rdi]
    xor rax, rax
    fptan
    fstsw ax
    fstp st0
    fstp tword [rdi]
    ret

abs80:
    xor rax, rax
    fld  tword [rdi]
    fabs
    fstsw ax
    fstp tword [rdi]
    ret

atan80:
    fld  tword [rsi]
    xor rax, rax
    fld  tword [rdi]
    fpatan
    fstsw ax
    fstp tword [rdi]
    ret

cmp80:
    fld  tword [rsi]
    xor rax, rax
    fld  tword [rdi]
    fcompp
    fstsw ax
    ret

round80:
    xor rax, rax
    fld  tword [rdi]
    fstcw word [rsp-4]
    mov ax, word [rsp-4]
    and ax, 0xf3ff
    shl rsi, 10
    or ax, si
    mov [rsp-8], eax
    fldcw word [rsp-8]
    frndint
    fldcw word [rsp-4]
    fstp tword [rdi]
    ret

f2xm180:
    fld  tword [rdi]
    xor rax, rax
    f2xm1
    fstsw ax
    fstp tword [rdi]
    ret

scale80:
    fld  tword [rsi]
    xor rax, rax
    fld  tword [rdi]
    fscale
    fstsw ax
    fstp tword [rdi]
    fstp st0
    ret

rem80:
    fld  tword [rsi]
    xor rax, rax
    fld  tword [rdi]
    fprem
    fstsw ax
    fstp tword [rdi]
    fstp st0
    ret