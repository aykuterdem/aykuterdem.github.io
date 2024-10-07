/* CS107
 * Lecture 10
 * ----------
 * This program is a sample program we will use to
 * explore what the assembly code version of our
 * program looks like.
 */


#include <stdio.h>
#include <stdlib.h>

int sum_array(int arr[], int nelems) {
    int sum = 0;
    for (int i = 0; i < nelems; i++) {
        sum += arr[i];
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int nums[] = {3, 5, 7, 9};
    int count = sizeof(nums) / sizeof(nums[0]);
    int total = sum_array(nums, count);
    printf("Sum = %d\n", total);
    return 0;
}



