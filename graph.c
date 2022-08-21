#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define H 25
#define W 80

void input(char **a);
void output(char **a);

/*int main() {

}
*/
void input(char **a) {
  int flag = 1;
  for (int i = 1; i < H; i++) {
    for (int j = 1; j < W; j++) {
      if (scanf("%c", &a[i][j]) != 1) {
        flag = 0;
        printf("%d%d", i, j);
      }
    }
  }
  return flag;
}

void output(char **a) {
  int i, j;
  for (i = 0; i < H; i++) {
    for (j = 0; j < W; j++) {
      printf("%c ", a[i][j]);
    }
    printf("%c\n", a[i][j]);
  }
}