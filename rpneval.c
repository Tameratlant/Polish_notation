#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415
#include "rpneval.h"

static double STACK[STACKSIZE];    // STACKSIZE defined in header file.
static double *SP = &STACK[0] - 1; // stack pointer - 1 char below so first
                                   // push_d will happen in right location.

int eval_rpn(double *result, char *expr) {

  char firstletter = 1;
  double a, b, c; // just variables to do operations with.
  char *pc;
  pc = expr;
  while (*pc != '\0') {
    if (*(pc - 1) == ' ' || *(pc - 1) == '\t' || firstletter) {
      firstletter = 0;
      if (*pc >= '0' && *pc <= '9') // it's a number... push_d it on the stack
      {
        c = atof(pc);
        push_d(c);
      } else if (*pc == '+')
        a = pop_d(), b = pop_d(), push_d(a + b);
      else if (*pc == '-') {
        if (*(pc + 1) >= '0' &&
            *(pc + 1) <= '9') // see if it's a negative number
        {
          c = atof(pc);
          push_d(c);
        } else // it's to subtract
          a = pop_d(), b = pop_d(), push_d(b - a);
      } else if (*pc == '*')
        a = pop_d(), b = pop_d(), push_d(a * b);
      else if (*pc == '/')
        a = pop_d(), b = pop_d(), push_d(b / a);
      else if (*pc == '%')
        a = pop_d(), b = pop_d(), push_d(fmod(b, a));
      else if (*pc == '^')
        a = pop_d(), b = pop_d(), push_d(pow(b, a));
      else if (*pc == 's')
        a = pop_d(), push_d(sin(a));
      else if (*pc == 'S')
        a = pop_d(), push_d(asin(a));
      else if (*pc == 'c')
        a = pop_d(), push_d(cos(a));
      else if (*pc == 'C')
        a = pop_d(), push_d(acos(a));
      else if (*pc == 't')
        a = pop_d(), push_d(tan(a));
      else if (*pc == 'T')
        a = pop_d(), push_d(atan(a));
      else if (*pc == 'l')
        a = pop_d(), push_d(log(a));
      else if (*pc == 'L')
        a = pop_d(), push_d(exp(a));
      else if (*pc == 'p')
        push_d(PI);
      else if (*pc == '#')
        printf("Top of stack: %f\n", *SP);
      else if (*pc == '@')
        printstack();
      else if (*pc == ']') // switch order
        a = pop_d(), b = pop_d(), push_d(a), push_d(b);
      else if (*pc == 'x')
        pop_d();
      else if (*pc == '\n' || *pc == ' ')
        ;
      else {
        printf("Invalid character: '%c'\n", *pc);
        exit(1);
      }
      /* //uncomment this part in order to see view stack each time (or use @).
      if(!(*pc == '\n' || *pc == ' '))
              printstack();
      */
    }
    pc++;
  }
  *result = *SP;

  SP = &STACK[0] - 1; // reset stack

  return 1;
}

void printstack(void) // for testing or while using @
{
  double *pc;
  pc = SP;
  printf("\n");
  printf("---------\n");
  while (pc >= &STACK[0]) {
    printf("%f\n", *pc);
    pc--;
  }
  printf("---------\n");
}

void push_d(double x) {
  if (SP >= &STACK[STACKSIZE - 1]) {
    printf("you have a stack overflow!\n");
    exit(-1);
  }
  ++SP;
  *SP = x;
}

double pop_d(void) {
  double tmp;

  if (SP < &STACK[0]) {
    printf("you have a stack underflow!\n");
    exit(1);
  }

  tmp = *SP; // thing on top of stack
  SP--;
  return tmp;
}
