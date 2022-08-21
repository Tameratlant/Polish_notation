#include "convert.h"


// typedef struct elem{
//     char* sign;
//     double num;
//     int prior;
//     int xflag;
// } elem;

// // char* input () {
// //     char * data;
// //     while (c = getchar c!= '\n') {
// //         data = realloc
// //         data[i] = c;
// //     }
// // }

int check_digit(char c) {
    int flag = 0;
    if (c < 58 && c > 47) flag = 1;
    return flag; 
}

int operationPriority(char c) {
    int flag = -1;
    if (c == '(') flag = 0;
    if (c == '+') flag = 1;
    if (c == '-') flag = 1;
    if (c == '*') flag = 2;
    if (c == '/') flag = 2;
    if (c == '^') flag = 3;
    if (c == '~') flag = 4;
    return flag;
}

// void prepare(char* in) {
//     int i = 0;
//     int len = strlen(in);
//     elem* data = calloc(len, sizeof(elem));
//     for (int i = 0; i < len; i++) {
//         if (check_digit(in[i]) == 1)
//     }

// }

// // void convert(char* in, char* out) {
    
// // }
// //48 - 57 - числа
// int main() {
//     char a = '9';
//     printf("%d", a);
// }

char* GetStringNumber(char* expr, int* pos) {
  //printf("\nPos %d\n", *pos);
  //	Хранит число
//   char strNumber[100] = "";
  char* strNumber = calloc(100, sizeof(char));
  int len = strlen(expr);
  //	Перебираем строку
  int i = *pos;
  for (; i < len; i++) {
    //printf("\nPos = %d\n", i);
    //	Разбираемый символ строки
    char num = expr[i];
	
    //	Проверяем, является символ числом
    if (check_digit(num) || num == '.') {
      //	Если да - прибавляем к строке
      char s[2];
      s[1] = '\0';
      s[0] = num;
      strcat(strNumber, s);
    //   strNumber += num;
    }
    else
    {
      //	Если нет, то перемещаем счётчик к предыдущему символу
      i--;
      //	И выходим из цикла
      break;
    }
  }

  //	Возвращаем число
  //printf("Pos = %d\n", i);
  *pos = i;
  return strNumber;
}

char* ToPostfix(char* infixExpr) {
    //	Выходная строка, содержащая постфиксную запись
    int len = strlen(infixExpr);

    //printf("\n%s\n", infixExpr);

    char* postfixExpr = calloc(22 * len, sizeof(char));
    //	Инициализация стека, содержащий операторы в виде символов

    stack* st = init();

		//	Перебираем строку
    for (int i = 0; i < len; i++) {
      //	Текущий символ
      //printf("\n%c\n", infixExpr[i]);
      char c = infixExpr[i];
      
      //	Если симовол - цифра
      if (check_digit(c)) {
         //	Парсии его, передав строку и текущую позицию, и заносим в выходную строку
         //printf("\n%c\n", c);
         postfixExpr = realloc (postfixExpr, sizeof(char));
         printf("i = %d", i);
         strcat(postfixExpr, GetStringNumber(infixExpr, &i));
         strcat(postfixExpr, " ");
      }
      //	Если открывающаяся скобка 
      else if (c == '(')
      {
        	//	Заносим её в стек
        	push(st, c);
      }
      //	Если закрывающая скобка
      else if (c == ')')
      {
        	//	Заносим в выходную строку из стека всё вплоть до открывающей скобки
          //while (stack.Count > 0 && stack.Peek() != '(')
          while (size(st) > 0 && peek(st) != '(') {
              char s[2];
              s[1] = '\0';
            s[0] = pop(st);
            printf("\nZnak = %s\n", s);
            strcat(postfixExpr, s);
            strcat(postfixExpr, " ");
          }
        	//	Удаляем открывающуюся скобку из стека
          pop(st);
      }
      	//Проверяем, содержится ли символ в списке операторов
        
      else if (operationPriority(c) != -1)
      {
        printf("\nznak = %c %d\n", c,operationPriority(c));
        //	Если да, то сначала проверяем
        char op = c;
        //	Является ли оператор унарным символом
        if (op == '-' && (i == 0 || (i > 1 && operationPriority( infixExpr[i-1] ) != -1)))
          //	Если да - преобразуем его в тильду
          op = '~';
          //printf("%c", op);
				//push(st, op);
        //	Заносим в выходную строку все операторы из стека, имеющие более высокий приоритет
        // while (stack.Count > 0 && ( operationPriority[stack.Peek()] >= operationPriority[op]))

        // peek(st);
        //printf("!%c!", peek(st));
        while (size(st) > 0 && ( operationPriority(peek(st)) >= operationPriority(op))) {
          printf("Current stack:");
          print_list(st->pointer);
          postfixExpr = realloc (postfixExpr, sizeof(char));
            char s[2];
            s[1] = '\0';
            s[0] = pop(st);
            printf("\nZnak = %s\n", s);
            strcat(postfixExpr, s);
            strcat(postfixExpr, " ");
          //strcat(postfixExpr, pop(st));
        }
                
        		// postfixExpr += stack.Pop();
				//	Заносим в стек оператор
        // stack.Push(op);
        push(st, op);
        //printf("!%c!", peek(st));
      }
    }
  	//	Заносим все оставшиеся операторы из стека в выходную строку
        list *p = st -> pointer;
        while (p != NULL) {
          char s[2];
          s[1] = '\0';
            s[0] = pop(st);
            printf("\nZZnak = %c\n", s[0]);
            // s1[0] = s[1];
            strcat(postfixExpr, s);
            strcat(postfixExpr, " ");
            p = p->next;
        }

  	//	Возвращаем выражение в постфиксной записи
    return postfixExpr;
}

