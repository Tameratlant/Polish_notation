#ifndef T11D17_0_SRC_STACK_H_
#define T11D17_0_SRC_STACK_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char value;
  struct node *next;
}list;

typedef struct Stack {
  list *pointer;
  int count;
}stack;

stack *init();

void delete_element(list *elem);

char peek(stack *st);

void push(stack *st, char value);

void destroy(stack *st);

void print_list(list *p_begin);

int pop(stack *st);

int size(stack *st);

int empty_check(stack *st);


#endif  // T11D17_0_SRC_STACK_H_
