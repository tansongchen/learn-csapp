int procprob1(int a, char b, long *u, char *v) {
  *u += a;
  *v += b;
  return sizeof(a) + sizeof(b);
}

int procprob2(int a, char b, long *u, char *v) {
  *u += a;
  *v += b;
  return sizeof(a) + sizeof(b);
}
