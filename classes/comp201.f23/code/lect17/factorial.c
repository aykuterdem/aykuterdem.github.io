#include<stdio.h>
#include<stdlib.h>

long factorial(long n) {
    long result;
    if (n > 1) {
        result = n * factorial(n - 1);
    } else {
        result = 1;
    }
    
    return result;
} 

int main(int argc, char *argv[]) {
    long num = 5;
    long factnum = factorial(num);
    printf("%ld! = %ld\n", num, factnum);
    return 0;
}
