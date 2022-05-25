#include <stdio.h>

int main() {
    char s[10];
    sprintf(s, "%.8x", 0x59b997fa); // 35 39 62 39 39 37 66 61
    printf("%s\n", s);
    return 0;
}
