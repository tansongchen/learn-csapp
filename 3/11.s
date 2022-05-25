impl1:
  movq %rdi, %rcx
  xorq %rcx, %rcx
  movq %rcx, %rax

impl2:
  movq %rdi, %rcx
  subq %rcx, %rcx
  movq %rcx, %rax

impl3:
  movq %rdi, %rcx
  movq $0, %rcx
  movq %rcx, %rax
