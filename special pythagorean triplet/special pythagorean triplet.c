#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
  int a,b;
  double c;
  int flag;
  for(a = 0; a < 500; a++){
    for(b = 0; b < 500; b++){
      c = sqrt((pow(a,2) + pow(b,2)));
      if((a+b+c) == 1000){
        flag = 1;
        break;
      }
    }
    if(flag == 1){
      break;
    }
  }
  printf("Answer: %i", (int)(a*b*c));
}
