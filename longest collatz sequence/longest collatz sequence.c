#include "stdio.h"
#include "stdlib.h"

#include <time.h>

long timediff(clock_t t1, clock_t t2) {
    long elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}

int main(int argc, char const *argv[]) {
  unsigned long numberOfTerms = 0;
  unsigned long currentTerm;
  unsigned long n;
  unsigned long longestNumberOfTerms = 0;
  unsigned long longestStartingNumber;
  clock_t t1, t2;
  long elapsed;
t1 = clock();
  for(n = 2; n <= 1000000; n++){
    currentTerm = n;
    while(currentTerm > 1){
      if(currentTerm % 2 == 0){
        currentTerm/=2;
      }else{
        currentTerm = 3*currentTerm + 1;
      }
      numberOfTerms++;
    }
    numberOfTerms++;
    if(numberOfTerms > longestNumberOfTerms){
      longestNumberOfTerms = numberOfTerms;
      longestStartingNumber = n;
    }
    numberOfTerms = 1;
  }
  printf("the longest sequence start in %lu and have %lu terms\n", longestStartingNumber, longestNumberOfTerms);
  t2 = clock();

    elapsed = timediff(t1, t2);
    printf("elapsed: %ld ms\n", elapsed);
  return 0;
}
