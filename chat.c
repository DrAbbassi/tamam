#include <stdio.h>

int main() {
  int i, j;
  for (i = 0; i < 11; i++) {
    for (j = 0; j < 11; j++) {
      if (i == 5 - j || i == 5 + j || i == j - 5 || i == -j + 15) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
