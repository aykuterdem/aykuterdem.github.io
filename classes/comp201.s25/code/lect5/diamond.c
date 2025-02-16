/**
 * CS107
 *
 * This program prints out the provided command line argument string
 * in a diamond pattern.  For instance, if you provide "DAISY" as a
 * command-line argument, it will print out the following pattern:
 *
 * D
 * DA
 * DAI
 * DAIS
 * DAISY
 *  AISY
 *   ISY
 *    SY
 *     Y
 */

#include <stdio.h>
#include <string.h>

void diamond(char *str) {
    int length = strlen(str);
    
    // print top half of diamond
    for (int i = 1; i <= length; i++) {
        char substr[i + 1];
        strncpy(substr, str, i);
        substr[i] = '\0';
        printf("%s\n", substr);
    }

    // print bottom half of diamond
    for (int i = 1; i < length; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }

        printf("%s\n", str + i);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Usage: ./diamond <TEXT>\n");
        return 0;
    } else {
        diamond(argv[1]);
    }
    
    return 0;
}
