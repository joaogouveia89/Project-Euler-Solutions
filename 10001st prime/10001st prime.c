#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define GOAL 10001



int isPrime(unsigned long n){
    unsigned long idx;
    for(idx = 2; idx <= sqrt(n); idx++){
        if(n % idx == 0){
            return 0;
        }
    }
    return 1;

}

int main(){
    int nPrimeNumber = 1;
    unsigned long current = 2;
    while(nPrimeNumber != GOAL){
        current++;
        if(isPrime(current) == 1){
            nPrimeNumber++;
        }
    }
    printf("Answer = %i\n", current);
}
