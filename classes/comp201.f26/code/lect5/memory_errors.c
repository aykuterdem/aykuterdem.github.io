/*
 * CS107
 * Lecture 5
 *
 * This program demonstrates memory-related issues that can arise
 * from either copying in too much data using strcpy, or asking for the
 * length of a character array without a null-terminating character.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void error1() {
    printf("--- Error 1: strcpy called on dst that is too small\n\n");
    
    char string1[6];
    strcpy(string1, "Hello");
    char string2[6];
    strcpy(string2, "Hello");
    
    // char *tooLongString = "abcdefg";
    char *tooLongString = "abcdefghijklmnopqrs";
    // char *tooLongString = "abcdefghijklmnopqrstuvwxyz";
    
    strcpy(string1, tooLongString);
    printf("string1 = %s\n", string1);
    printf("string2 = %s\n", string2);
    printf("\n");
}

void error2() {
    printf("--- Error 2: strlen called on string without null terminator\n\n");

    char string[10];
    strncpy(string, "Stanford", 3);
    
    int length = strlen(string);
    printf("strlen(non-terminated \"Sta\") = %d\n\n", length); 
}

int main(int argc, char *argv[]) {
    error1();
    // error2();

    printf("Done.\n");
    return 0;
}
