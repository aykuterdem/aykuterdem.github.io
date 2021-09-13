/*
 * CS107
 * Lecture 5
 *
 * This program creates and manipulates strings to let us
 * examine the memory behavior of strings in C.
 */

#include <stdio.h>
#include <string.h>

void modifyFirstChar(char *str) {
    printf("modifyFirstChar: sizeof(str) = %lu\n", sizeof(str));
    str[0] = 'h';
}

int main(int argc, char *argv[]) {
    char str1[] = "Hi!";

    printf("main: sizeof(str1) = %lu\n", sizeof(str1));

    char *str1Ptr = str1;
    printf("main: sizeof(str1Ptr) = %lu\n", sizeof(str1Ptr));

    printf("main (before): str1 = %s\n", str1);
    modifyFirstChar(str1);
    printf("main (after): str1 = %s\n", str1);
    
    return 0;
}
