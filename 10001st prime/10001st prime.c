#include<stdlib.h>
#include<stdio.h>
#define GOAL 10001


int isPrime(unsigned int n){
    unsigned int idx;
    for(idx = 2; idx <= (n/2); idx++){
        if(n % idx == 0){
            return 0;
        }
    }
    return 1;

}

int main(){
    int nPrimeNumber = 1;
    unsigned int current = 2;

    while(nPrimeNumber != GOAL){
        current++;
        if(isPrime(current) == 1){
            nPrimeNumber++;
        }
    }
    printf("Answer = %i", current);
}
