typedef union {
  struct {
    long u;
    short v;
    char w;
  } t1;
  struct {
    int a[2];
    char *p;
  } t2;
} u_type;

void get1(u_type *up, long *dest) {
  *dest = up->t1.u;
  // movq (%rdi), %rax; movq %rax, (%rsi)
}

void get2(u_type *up, short *dest) {
  *dest = up->t1.v;
  // movw 8(%rdi), %ax; movw %ax, (%rsi)
}

void get3(u_type *up, char **dest) {
  *dest = &up->t1.w;
  // leaq 10(%rdi), %rax; movq %rax, (%rsi)
}

void get4(u_type *up, int **dest) {
  *dest = up->t2.a;
  // movq %rdi, (%rsi)
}

void get5(u_type *up, int *dest) {
  *dest = up->t2.a[up->t1.u];
  // movq (%rdi), %rax; movl (%rdi, %rax, 4), %eax; movl %eax, (%rsi)
}

void get6(u_type *up, char *dest) {
  *dest = *up->t2.p;
  // movq 8(%rdi), %rax; movb (%rax), %al; movb %al, (%rsi)
}
