void switcher(long a, long b, long c, long *dest) {
  long val;
  switch (b) {
    case 5: c = a ^ 15;
    case 0: val = c + 112; break;
    case 2: case 7: val = (a + c) >> 2; break;
    case 4: val = b; break;
    default: val = a;
  }
  *dest = val;
}
