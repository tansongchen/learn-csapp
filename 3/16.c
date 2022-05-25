void cond(short a, short *p) {
  if (!a) goto final;
  if (*p < a) goto final;
  *p = a;
  final:
    return;
}
