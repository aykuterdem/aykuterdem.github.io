/*
 * CS107
 * Lecture 6
 *
 * This program removes leading whitespace from an entered command line
 * argument string and lets us examine the memory layout of a program using
 * pointers to pointers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function changes the string pointer pointed to by strPtr
 * to skip over any leading whitespace (just regular spaces).
 */
void skipSpaces(char **strPtr) {
    int numSpaces = strspn(*strPtr, " ");
    *strPtr += numSpaces;
}

int main(int argc, char *argv[]) {
    char *str = "    hello";
    skipSpaces(&str);
    printf("%s\n", str);
    return 0;
}
