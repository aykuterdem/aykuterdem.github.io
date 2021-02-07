/**
 * COMP201 Lecture 3
 * Aykut Erdem (Code written by Nick Troccoli, Stanford CS107)
 * ------------------------
 * This program shows some of the limitations of integer representations!  Why does it behave
 * in this way?
 *
 * Note: this is based on a real bug that occurred with an
 * airline in 2004: https://arstechnica.com/uncategorized/2004/12/4490-2/
 */

#include <stdio.h>     // for printf
#include <unistd.h>    // for sleep

 // argc and argv are ignored by this particular program
int main(int argc, char *argv[]) {
  short airlineCrewChangesThisMonth = 0;
  
  // Simulate accumulating crew changes over time
  for (int i = 0; i < 31; i++) {
      
    // Pretend there are a certain number of crew changes per day
    airlineCrewChangesThisMonth += 1200;
    printf("Crew changes by end of day %d: %d\n", i + 1, airlineCrewChangesThisMonth);
  }
  
  return 0;
}
