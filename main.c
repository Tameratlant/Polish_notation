#include "convert.h"
#include "stack.h"
#include "rpneval.h"

int main () {
    char * s;
    char buf[256];
	// double result;
    s = calloc(256, sizeof(char));

    char* infixExpr = calloc(256, sizeof(char));

    char* withoutx = calloc(256, sizeof(char));

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
    


	// eval_rpn(&result, s);
	// printf("result = %f\n", result);
    //printf("%s", GetStringNumber("1.5123", &i));
    // free(ToPostfix);
    // free(s);
    return 0;





}
