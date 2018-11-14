#include "stdlib.h"
#include "stdio.h"
#include "math.h"

long long sumOfNumbers(long long);
int numberOfDivisors(long long n);

int main() {
  int nod = 0;
  long long son;
  int ref;
  for(ref = 0; nod <= 500; ref++){
    son = sumOfNumbers(ref);
    nod = numberOfDivisors(son);
  }
  printf("\n\nthe number with 500 divisors is = %llu with %i divisors\n\n", son, nod);
  return EXIT_SUCCESS;
}

long long sumOfNumbers(long long n){
  return (n*(n+1)/2);
}

int numberOfDivisors(long long n){
  int ref;
  int numDivisors = 0;
  for(ref = 1; ref <= sqrt(n); ref++){
    /* The factors occur in pairs and its enough to find the factors up
     to the square root of the triangle number and increment the count by two each time a factor is found.*/
    if(n%ref == 0){
      numDivisors+=2;
    }
  }
  numDivisors++;
  return numDivisors;
}
