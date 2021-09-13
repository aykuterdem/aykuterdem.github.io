/*
 * CS107
 * Lecture 15
 *
 * This program demonstrates the loop unrolling compiler
 * optimization when compiled with -O2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int char_sum(char *s) {
    int sum = 0;
    for (size_t i = 0; i < strlen(s); i++) {
        sum += s[i];
    }
    return sum;
}

void lower1(char *s) {
    for (size_t i = 0; i < strlen(s); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] -= ('A' - 'a');
        }
    }
}

int main(int argc, char *argv[]) {
    char buf[strlen(argv[1]) + 1];
    strcpy(buf, argv[1]);
    printf("Char sum before: %d\n", char_sum(buf));
    lower1(buf);
    printf("%s -> %s\n", argv[1], buf);
    printf("Char sum after: %d\n", char_sum(buf));
    return 0;
}
