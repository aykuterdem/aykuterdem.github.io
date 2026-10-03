/*
 * CS107
 * Lecture 15
 *
 * This program demonstrates the dead code compiler
 * optimization when compiled with -O2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int dead_code(int param1, int param2) {
    if (param1 < param2 && param1 > param2) {
        printf("This test can never be true!\n");
    }

    // Empty for loop
    for (int i = 0; i < 1000; i++);

    // If/else that does the same operation in both cases
    if (param1 == param2) {
        param1++;
    } else {
        param1++;
    }

    // If/else that more trickily does the same operation in both cases
    if (param1 == 0) {
        return 0;
    } else {
        return param1;
    }
}
    
int main(int argc, char *argv[]) {
    return 0;
}
