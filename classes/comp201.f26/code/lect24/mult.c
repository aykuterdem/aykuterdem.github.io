#include "fcyc.h"
#include <stdlib.h>
#include <stdio.h>

#define DIM 100

/* Multiply square matrices a and b, result stored in c */
void mmm(double a[][DIM], double b[][DIM], double c[][DIM], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}


int main(int argc, char *argv[]) {
    double a[DIM][DIM];
    double b[DIM][DIM];
    double c[DIM][DIM];
    for (int n = 25; n <= DIM; n *=2) {
	    start_counter();
	    mmm(a, b, c, n);
	    printf("matrix multiply %3d^2: cycles %6.2fM %s\n", n, get_counter() / 1e6, LABEL);
	}
}
