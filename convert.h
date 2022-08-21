#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int operationPriority(char c);

int check_digit(char c);

char* GetStringNumber(char* expr, int* pos);

char* ToPostfix(char* infixExpr);

char* no_sin(char * in);

int check_sin(char *str, int pos);

int check_cos(char *str, int pos);

int check_tan(char *str, int pos);

int check_ctg(char *str, int pos);

char* convert_x(char* str, double x);
