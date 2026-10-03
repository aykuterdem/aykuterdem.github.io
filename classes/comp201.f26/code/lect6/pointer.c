#include <stdio.h>

int main(int argc, char *argv[]) {

  int x = 2;

  // Make a pointer that stores the address of x.
  // (& means "address of")
  int *xPtr = &x;

  // Dereference the pointer to go to that address.
  // (* means "dereference")
  printf("The value at %p is %d\n", xPtr, *xPtr);	// prints the address information and the value 2

  return 0;
}
