#include <stdio.h>
#include <string.h>

char* reverseString(char* s) {
    // if string is null
    if( s == 0 )
        return NULL;

    // if string is empty
    if( *s == 0 )
        return s;

    char *start = s;
    char *end = s + strlen(s) - 1;
    char temp;

    while( end > start ) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    return s;
}

int main(void) {
    char str[] = "hello";

    printf("%s\n", reverseString(str));

    return 0;
}
