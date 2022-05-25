#include <stdio.h>

long fact(int n) {
  long result = 1;
  do {
    result *= n;
    n = n - 1;
  } while (n > 1);
  return result;
}

int main() {
  printf("%ld\n", fact(14));
}
