/* COMP201 Lecture 4
 * Aykut Erdem (code written by Chris Gregg, Stanford CS107)
 * ------
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   float a = 3.14;
   float b = 1e20;

   float c = (a + b) - b;
   float d = a + (b - b);

   printf("(3.14 + 1e20) - 1e20 = %f\n", c);
   printf("3.14 + (1e20 - 1e20) = %f\n", d);

   return 0;
}

