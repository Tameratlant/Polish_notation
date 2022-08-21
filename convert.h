#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int operationPriority(char c);

int check_digit(char c);

char* GetStringNumber(char* expr, int* pos);

char* ToPostfix(char* infixExpr);

