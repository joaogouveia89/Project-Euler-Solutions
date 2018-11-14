#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

long timediff(clock_t t1, clock_t t2) {
    long elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}

//compile with -lm flag
int sumOfSquares(int);
int main(){
    clock_t t1, t2;
    long elapsed;
    t1 = clock();
  int res = pow(sum(100),2) - sumOfSquares(100);
  printf("Answer = %i\n", res);
  t2 = clock();

    elapsed = timediff(t1, t2);
    printf("elapsed: %ld ms\n", elapsed);
  return EXIT_SUCCESS;
}

int sumOfSquares(int x){
  if(x != 1){
    return (pow(x,2) + sumOfSquares(x-1));
  }else{
    return pow(x,2);
  }
}
int sum(int x){
  if(x != 1){
    return (x + sum(x-1));
  }else{
    return x;
  }
}
