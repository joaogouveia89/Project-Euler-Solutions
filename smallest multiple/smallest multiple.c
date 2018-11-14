#include <stdlib.h>
#include <stdio.h>
#define MAX_NUM 20

int main(){
  int n = 10;
  /*considering that from 1 to 10 it is impossible to divide by all numbers
  and left no reminder, as some numerators will be less than the denominators
  */
  int forNum;
  int flag = 0;
  while(flag == 0){
    n++;
    for(forNum = 2; forNum <= MAX_NUM; forNum++){
      if(n % forNum != 0){
        flag = 0;
        break;
      }
      if(forNum == MAX_NUM){
        flag = 1;
        break;
      }
    }
  }
  printf("Answer %i\n", n);
}
