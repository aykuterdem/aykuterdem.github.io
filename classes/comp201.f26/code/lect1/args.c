/* COMP201 Lecture 2
 * Aykut Erdem (adapted from the code examples in Nick Troccoli's CS107 class)
 * ----
 * This program prints out information about
 * its received command-line arguments.
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("This program received %d argument(s)\n", argc);
    
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
