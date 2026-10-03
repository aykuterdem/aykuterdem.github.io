/*
 * CS107
 * Lecture 15
 *
 * This program demonstrates the constant folding compiler
 * optimization when compiled with -O2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int fold(int param) {
    char arr[5];
    int a = 0x107;
    int b = a * sizeof(arr);
    int c = sqrt(2.0);
    return a * param + (a + 0x15/c + strlen("Hello") * b - 0x37) / 4;
}

int main(int argc, char *argv[]) {
    return 0;
}
