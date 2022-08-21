#include "convert.h"
#include "rpneval.h"
#include "stack.h"

int main() {
  char *s;
  char* buf = calloc(256, sizeof(char));
  double result;

  char *infixExpr;

  char *withoutx;

  // char res[256];

  fgets(buf, 256, stdin);

  infixExpr = no_sin(buf);

  printf("With x\n");

  printf("\n%s\n", infixExpr);

  s = ToPostfix(infixExpr);

  printf("With x\n");

  printf("\n%s\n", s);

  withoutx = convert_x(s, 1.5);

  printf("Without x\n");

  printf("\n%s\n", withoutx);

  // printf("\n%s\n", withoutx);

  eval_rpn(&result, withoutx);
  printf("result = %f\n", result);
  // printf("%s", GetStringNumber("1.5123", &i));
   free(infixExpr);
   free(s);
   free(withoutx);
  return 0;
}
