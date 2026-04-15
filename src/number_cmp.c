/* number compare */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RESULT_SIZE 16

int compare(int num1, int num2) {
    int ret;
    char result[RESULT_SIZE];
    memset(result, 0, RESULT_SIZE);
    if (num1 < num2) {
        snprintf(result, RESULT_SIZE, "less than");
        ret = -1;
    } else if (num1 == num2) {
        snprintf(result, RESULT_SIZE, "equals to");
        ret = 0;
    } else {
        snprintf(result, RESULT_SIZE, "more than");
        ret = 1;
    }

    printf("num1:[%d] %s num2:[%d]\n", num1, result, num2);

    return ret;
}

int main(int argc, char *argv[]) {
    int number1;
    int ret, i;

    printf("Input:");
    scanf("%d", &number1);
    
    for (i = 0; i < argc; i++) {
        printf("argv[%d]:[%s]\n", i, argv[i]);
    }

    ret = compare(110, 13);
    printf("ret:[%d]\n", ret);
    printf("print numbers done\n");

    return 0;
}



