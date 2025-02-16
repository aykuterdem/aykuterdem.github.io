/* COMP201 Lecture 4
 * Aykut Erdem (code written by Chris Gregg, Stanford CS107)
 * ------
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   double a = 0.1;
   double b = 0.2;
   double c = 0.3;
   double d = a + b;
   
   printf("0.1 + 0.2 == 0.3 ? %s\n", a + b == c ? "true" : "false");
   printf("d: %.10lf\n", d);

   return 0;
}

