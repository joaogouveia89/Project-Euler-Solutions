#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[]) {
  unsigned long numberOfTerms = 0;
  unsigned long currentTerm;
  unsigned long n;
  unsigned long longestNumberOfTerms = 0;
  unsigned long longestStartingNumber;

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
  return 0;
}
