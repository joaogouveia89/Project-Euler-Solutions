#include <stdlib.h>
#include <stdio.h>

int main(){
  int a = 1;
  int n;
  int sum = 0;
  for(n = 1; n < 1000; n++){
    if(n % 3 == 0 || n % 5 == 0){
      sum += n;
      a++;
    }
  }
  printf("----------\n");
  printf("Total: %i\n\n", sum);
}
