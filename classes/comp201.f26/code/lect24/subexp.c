/*
 * CS107
 * Lecture 15
 *
 * This program demonstrates the common subexpression
 * elimination compiler optimization when compiled with -O2.
 */

#include <stdio.h>
#include <stdlib.h>

int subexp(int param1, int param2) {
    int a = (param2 + 0x107);
    int b = param1 * (param2 + 0x107) + a;
    return a * (param2 + 0x107) + b * (param2 + 0x107);
}

int main(int argc, char *argv[]) {
    return 0;
}
