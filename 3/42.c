struct ace {
  short v;
  struct ace *p;
};

short test(struct ace *ptr) {
  int val = 1;
  while (ptr) {
    val *= ptr->v;
    ptr = ptr->p;
  }
  return val;
}
