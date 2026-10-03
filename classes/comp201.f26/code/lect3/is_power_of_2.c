/* COMP201 Lecture 4
 * Aykut Erdem (code written by Nick Troccoli, Stanford CS107)
 * ------
 * This program takes a single command-line argument and prints
 * out whether or not this number is a power of 2.  It does this
 * using bitwise operators.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// The max number to use for testing power of 2
#define TEST_MAX 20

/* This function uses bitwise operators to return whether or not
 * this number is a power of 2. */
bool is_power_of_2(unsigned int value) {
  	return value != 0 && (value & (value - 1)) == 0;
}

// This function prints out whether or not the value is a power of 2.
void print_is_power_of_2(unsigned int value) {
	if (is_power_of_2(value)) {
		printf("%d is a power of 2\n", value);	
	} else {
		printf("%d is not a power of 2\n", value);	
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		/* If no argument provided, print out for
		 * 1-20 whether they are powers of 2.
		 */
		for (int i = 1; i <= TEST_MAX; i++) {
			print_is_power_of_2(i);
		}
	} else {
	    int value = atoi(argv[1]);
	    print_is_power_of_2(value);
	}

    return 0;
}

