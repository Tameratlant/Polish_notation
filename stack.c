#include "stack.h"

/*
Разработать программу src/stack.c, в которой содержатся реализации функций по
работе с динамическим стеком (init, push, pop, destroy). Объявления функций и
структуры динамического стека, хранящего целые числа, вынести в src/stack.h.
Написать модульные тесты для проверки работы функций push и pop стека в
src/stack_test.c. Функции методов должны возвращать SUCCESS в случае успешного
прохождения теста и FAIL - в случае ошибки. Тесты должны собираться при помощи
Makefile. Имя стадии - stack_test. Исполняемый файл должен располагаться в корне
репозитория в папке build и иметь имя Quest_3. Обратите внимание: этот квест
будет тестироваться утилитой cppcheck ==
*/

stack *init() {
  stack *temp = (stack *)malloc(sizeof(stack));
  temp->pointer = NULL;
  temp->count = 0;
  return temp;
}

void delete_element(list *elem) {
  if (elem->next)
    delete_element(elem->next);
  free(elem);
}

void destroy(stack *st) {
  if (!st)
    return;
  if (st->pointer)
    delete_element(st->pointer);
  free(st);
}

void print_list(list *p_begin) {
  list *p = p_begin;
  while (p != NULL) {
    printf("%c ", p->value);
    p = p->next;
  }
}

char peek(stack *st) {
  // if (!st || !st->pointer || size(st) == 0)
  if (size(st) == 0)
    exit (1);
  // int value = ;
  return st->pointer->value;
}

void push(stack *st, char value) {
  if (!st)
    return;
  list *temp = (list *)malloc(sizeof(list));
  temp->value = value;
  if (!st->pointer) {
    temp->next = NULL;
    st->pointer = temp;
  } else {
    temp->next = st->pointer;
    st->pointer = temp;
  }
  st->count++;
}

int pop(stack *st) {
  if (!st || !st->pointer)
    return 0;
  int value = st->pointer->value;
  list *del = st->pointer;
  st->pointer = st->pointer->next;
  free(del);
  st->count--;
  return value;
}

int size(stack *st) { return st->count; }

int empty_check(stack *st) { return !st->pointer; }

// int main () {
//   stack *st = init();
//   for (int i = 5; i < 10; ++i) {
//     push(st, i);
//   }
// }
