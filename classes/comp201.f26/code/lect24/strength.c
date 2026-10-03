/*
 * CS107
 * Lecture 15
 *
 * This program demonstrates the strength reduction compiler
 * optimization when compiled with -O2.
 */

#include <stdio.h>
#include <stdlib.h>

int strength(int param1[], int param2) {
    int a = param2 * 32;
    int b = a * 7;
    int c = b / 3;
    int d = param2 % 2;

    for (int i = 0; i <= param2; i++) {
        c += param1[i] + 0x107 * i;
    }
    return c + d;
}

int main(int argc, char *argv[]) {
    return 0;
}
