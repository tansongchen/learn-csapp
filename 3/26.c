long test_one(unsigned long x) {
  long val = 1;
  while (x != 0) {
    val = val ^ x;
    x = x >> 1;
  }
  return val & 0xFFFFFFFF00000000L;
}
