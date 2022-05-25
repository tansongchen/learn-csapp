long test_two(unsigned long x) {
  short val = 65;
  short i;
  for (i = 1; x != 0; ++i) {
    val = (val + val) & (x & 1);
    x = x >> 1;
  }
  return val;
}
