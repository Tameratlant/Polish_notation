#include "convert.h"
#include "stack.h"
#include "rpneval.h"

int main () {
    char * s;
    char buf[256];
	double result;
    s = calloc(256, sizeof(char));
    fgets(buf, 256, stdin);
    s = ToPostfix(buf);
    printf("\n%s\n", s);
    
	eval_rpn(&result, s);
	printf("result = %f\n", result);
    //printf("%s", GetStringNumber("1.5123", &i));
    // free(ToPostfix);
    // free(s);
    return 0;
}

// char *pc;
// 	char buf[256];
// 	double result;
	
// 	while(1)
// 	{
// 		printf("Enter Expression. Example: 2 3 4 + *(= (3+4)*2). ctrl + C to exit:\n");
// 		fgets(buf, 256, stdin);
// 		eval_rpn(&result, buf);
// 		printf("result = %f\n", result);
// 	}