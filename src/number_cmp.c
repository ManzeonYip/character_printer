/* number compare */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RESULT_SIZE 16

typedef struct Printer Printer;

struct Printer {
    int radius;
    char character;
    int (*show)(Printer *self);
    int (*print)(Printer *self);
};

int show_func(Printer *p) {
    if (p == NULL) {
        printf("p is null\n");
    }
    printf("radius:[%d] character:[%c]\n", p->radius, p->character);

    return 0;
}

int print_char_num(int radius, char character) {
    int i;

    for (i = 0; i < radius; i++) {
        printf("%c", character);
    }
    printf("\n");

    return 0;
}

int print_inc(int radius, char character) {
    int i;

    for (i = 0; i < radius; i++) {
        print_char_num(i, character);
    }

    return 0;
}

int print_dec(int radius, char character) {
    int i;

    for (i = radius; i > 0; i--) {
        print_char_num(i, character);
    }

    return 0;
}

int print_func(Printer *p) {
    if (p == NULL) {
        printf("p is null\n");
        return -1;
    }
    
    print_inc(p->radius, p->character);
    print_dec(p->radius, p->character);

    return 0;
}

Printer *create_printer(int radius, char character) {
    Printer *pt = malloc(sizeof(Printer));
    if (pt == NULL) {
        printf("pt malloc failed\n");
    }

    pt->radius = radius;
    pt->character = character;
    pt->show = show_func;
    pt->print = print_func;

    return pt;
}

void destroy_printer(Printer *pt) {
    free(pt);
    pt = NULL;
}

int printer_test(int num, char c) {
    Printer *pt = NULL;

    pt = create_printer(num, c);
    if (pt == NULL) {
        printf("create printer failed\n");
        return -1;
    }

    printf("================= printer show ===============\n");
    pt->show(pt);
    printf("================= printer print ==============\n");
    pt->print(pt);

    destroy_printer(pt);

    return 0;
}


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

int main_test(int argc, char *argv[]) {
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

int main(int argc, char *argv[]) {
    int ret;
    int num;
    char c;

    printf("argc:[%d] argv[0]:[%s]\n", argc, argv[0]);

    printf("Input radius:");
    scanf("%d", &num);

    printf("Input character:");
    scanf(" %c", &c);

    ret = printer_test(num, c);
    printf("ret:[%d]\n", ret);

    return 0;
}

