uremdiv:
  movq %rdx, %r8
  movq %rdi, %rax
  movq $0, %rdx
  divq %rsi
  movq %rax, (%r8)
  movq %rdx, (%rcx)
  ret
