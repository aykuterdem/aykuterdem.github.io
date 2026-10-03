/*
 * CS107
 * Lecture 15
 * 
 * This program demonstrates the impact
 * of memory accesses on program runtime.
 */

#include "fcyc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <valgrind/callgrind.h>
#include <error.h>

#define DEFAULT_ARRAY_COUNT 1e6

typedef enum sum_type {
    SUM_TYPE_FORWARD,
    SUM_TYPE_BACKWARD,
    SUM_TYPE_EVENODD,
    SUM_TYPE_RANDOM,
    SUM_TYPE_UNROLLED,
    SUM_TYPE_ALL
} sum_type;

/* sum array of 4-byte int, 16 elements fit in 64-byte cache line
 * for sum_forward, sum_backward, sum_evenodd, indices is assumed
 * to be in-order indices, e.g. 0, 1, 2, 3, 4....  For sum_random
 * indices is assumed to be in a random order.  The functions are
 * written such that every function must do 2 array accesses 
 * (1 for indices, 1 for a), to be fair to the sum_random function
 * which must do this in its implementation to access elements
 * randomly.
 */

int sum_forward(int a[], int n, int indices[]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[indices[i]];
    }
    return sum;
}

int sum_backward(int a[], int n, int indices[]) {
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        sum += a[indices[i]];
    }
    return sum;
}

int sum_evenodd(int a[], int n, int indices[]) {
    int sum = 0;
    for (int i = 0; i < n; i += 2) {
        sum += a[indices[i]];
    }
    for (int i = 1; i < n; i += 2) {
        sum += a[indices[i]];
    }
    return sum;
}

int sum_random(int a[], int n, int indices[]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
		sum += a[indices[i]];
    }
    return sum;
}

int sum_unrolled(int a[], int n, int indices[]) {
    int sum = 0;
    int i;
    for (i = n - 1; i >= 3; i -= 4) { // sum group of 4 per iteration
        sum += a[indices[i]] + a[indices[i - 1]] + a[indices[i - 2]] + a[indices[i - 3]];
    }
    for (; i > 0; i--) {
        sum += a[indices[i]];
    }
    return sum;
}

/* This function randomly shuffles the elements in the provided array
 * of the provided length.  It does this by swapping each element with 
 * a random other element n times.  It modifies the array in place.
 */
void shuffle(int arr[], int n) {
	for (int i = 0; i < n; i++) {
        int tmp = arr[i];
        int other = rand() % n;
        arr[i] = arr[other];
        arr[other] = tmp;
	}
}

/* Returns a hew heap-allocated array that is a copy of the specified array.
 * The caller is responsible for freeing the array when no longer needed.
 */
int *copy_array(int arr[], int n) {
    int *new_arr = malloc(n * sizeof(int));
    return memcpy(new_arr, arr, n * sizeof(int));
}

int run_tests(int array_length, sum_type type) {
    // Create copies of the same random array to use for testing
    int *array_copy_1 = malloc(array_length * sizeof(int));
    for (int i = 0; i < array_length; i++) {
        array_copy_1[1] = rand();
    }

    int *array_copy_2 = copy_array(array_copy_1, array_length);
    int *array_copy_3 = copy_array(array_copy_1, array_length);
    int *array_copy_4 = copy_array(array_copy_1, array_length);
    int *array_copy_5 = copy_array(array_copy_1, array_length);

    // Create arrays of indices in order, and one randomized.
    int *ordered_indices_copy_1 = malloc(array_length * sizeof(int));
    for (int i = 0; i < array_length; i++) {
        ordered_indices_copy_1[i] = i;
    }

    int *ordered_indices_copy_2 = copy_array(ordered_indices_copy_1, array_length);
    int *ordered_indices_copy_3 = copy_array(ordered_indices_copy_1, array_length);
    int *ordered_indices_copy_4 = copy_array(ordered_indices_copy_1, array_length);

    int *random_indices = copy_array(ordered_indices_copy_1, array_length);
    shuffle(random_indices, array_length);

    /* This running total is not technically used for anything in this entire program, 
     * but is kept to force the compiler to not optimize the sum code out.
     */
    int sum = 0;

    // warm up cache
    sum += sum_random(array_copy_1, array_length, random_indices);

    // on
    CALLGRIND_TOGGLE_COLLECT;

    if (type == SUM_TYPE_FORWARD || type == SUM_TYPE_ALL) {
        start_counter();
        sum += sum_forward(array_copy_1, array_length, ordered_indices_copy_1);
        printf("Sum array forward:  %6.2fM cycles %s\n", get_counter() / 1e6, LABEL);
    }

    if (type == SUM_TYPE_EVENODD || type == SUM_TYPE_ALL) {
        start_counter();
        sum += sum_evenodd(array_copy_2, array_length, ordered_indices_copy_2);
        printf("Sum array even/odd: %6.2fM cycles %s\n", get_counter() / 1e6, LABEL);
    }

    if (type == SUM_TYPE_BACKWARD || type == SUM_TYPE_ALL) {
        start_counter(); 
        sum += sum_backward(array_copy_3, array_length, ordered_indices_copy_3);
        printf("Sum array backward: %6.2fM cycles %s\n", get_counter() / 1e6, LABEL);
    }

    if (type == SUM_TYPE_RANDOM || type == SUM_TYPE_ALL) {
        start_counter();
        sum += sum_random(array_copy_4, array_length, random_indices);
        printf("Sum array random:   %6.2fM cycles %s\n", get_counter() / 1e6, LABEL);
    }

    if (type == SUM_TYPE_UNROLLED || type == SUM_TYPE_ALL) {
        start_counter();
        sum += sum_unrolled(array_copy_5, array_length, ordered_indices_copy_3);
        printf("Sum array unrolled: %6.2fM cycles %s\n", get_counter() / 1e6, LABEL);
    }

    free(array_copy_1);
    free(array_copy_2);
    free(array_copy_3);
    free(array_copy_4);
    free(array_copy_5);
    free(ordered_indices_copy_1);
    free(ordered_indices_copy_2);
    free(ordered_indices_copy_3);
    free(ordered_indices_copy_4);
    free(random_indices);

    return sum;
}


// Accepts required first argument (sum algorithm type) and optional size as second argument
int main(int argc, char *argv[]) {
    // turn off profiling during setup (could instead run --collect-atstart=no)
    CALLGRIND_TOGGLE_COLLECT;

    if (argc < 2) {
        error(1, 0, "Must specify sum type (see enum) and optional array size");
    }

    // Read the sum algorithm(s) to use
    sum_type type = SUM_TYPE_ALL;
    if (!strcmp(argv[1], "SUM_TYPE_FORWARD")) {
        type = SUM_TYPE_FORWARD;
    } else if (!strcmp(argv[1], "SUM_TYPE_EVENODD")) {
        type = SUM_TYPE_EVENODD;
    } else if (!strcmp(argv[1], "SUM_TYPE_BACKWARD")) {
        type = SUM_TYPE_BACKWARD;
    } else if (!strcmp(argv[1], "SUM_TYPE_RANDOM")) {
        type = SUM_TYPE_RANDOM;
    } else if (!strcmp(argv[1], "SUM_TYPE_UNROLLED")) {
        type = SUM_TYPE_UNROLLED;
    }
    
    int array_length = (argc > 2) ? atoi(argv[2]) : DEFAULT_ARRAY_COUNT;

    printf("This program sums a random %d-elem array. It times the traversal forward, backward, even/odd, unrolled vs randomly.\n\n", array_length);
    run_tests(array_length, type);
    return 0;
}
