long lt_cnt = 0;
long ge_cnt = 0;
long absdiff_se(long x, long y) {
  long result;
  if (x < y) {
    lt_cnt++;
    result = y - x;
  } else {
    ge_cnt++;
    result = x - y;
  }
  return result;
}

long gotodiff_se(long x, long y) {
  long result;
  if (x < y)
    goto true_statement;
  ge_cnt++
  result = y - x;
  true_statement:
    lt_cnt++;
    result = y - x;
  done:
    return result;
}
