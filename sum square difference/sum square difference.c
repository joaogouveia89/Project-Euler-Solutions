#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//compile with -lm flag
int sumOfSquares(int);
int main(){
  int res = pow(sum(100),2) - sumOfSquares(100);
  printf("Answer = %i\n", res);
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
