/*
 * COMP201
 * Lecture R13
 *§
 * This program implements a generic swap function that
 * works for any variable type.  It also shows how you
 * can call the function incorrectly and what happens in
 * memory if you do so.
 */

#include <stdio.h>
#include <string.h>

/* This is a generic swap function that can swap the data pointed
 * to by the two pointers, of the given size in bytes.
 */
void swap(void *data1ptr, void *data2ptr, size_t nbytes) {
    char temp[nbytes];
    memcpy(temp, data1ptr, nbytes);
    memcpy(data1ptr, data2ptr, nbytes);
    memcpy(data2ptr, temp, nbytes);
}

int main(int argc, char *argv[]) {
    // Example 1
    int x = 0xffffffff;
    int y = 0xeeeeeeee;
    printf("BEFORE: x = 0x%x, y = 0x%x\n", x, y);
    swap(&x, &y, sizeof(x));
    // swap(&x, &y, sizeof(short));  // what happens if we do this?
    printf("AFTER: x = 0x%x, y = 0x%x\n", x, y);

    // Example 2
    char string1[10] = "Hello";
    char string2[10] = "Goodbye";
    printf("BEFORE: string1: %s\n", string1);
    printf("BEFORE: string2: %s\n", string2);
    swap(string1, string2, sizeof(string1));
    //swap(string1, string2, sizeof(int));  // what happens if we do this?
    printf("AFTER: string1: %s\n", string1);
    printf("AFTER: string2: %s\n", string2);
    return 0;
}
