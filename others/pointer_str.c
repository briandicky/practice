#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char s[] = "0113256";
    char *p = s;

    printf("s[] = %s\n", s);

    printf("*p++:\t%c\n", *p++);
    printf("*(p++):\t%c\n", *(p++));
    printf("(*p)++:\t%c\n", (*p)++);
    printf("*++p:\t%c\n", *++p);
    printf("*(++p):\t%c\n", *(++p));
    printf("++*p:\t%c\n", ++*p);
    printf("++(*p):\t%c\n", ++(*p));

    return 0;
}
