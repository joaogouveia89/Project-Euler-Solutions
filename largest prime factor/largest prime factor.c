#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define GOAL 600851475143

/**
* This function checks if there's a divisor >= 2 and < n/2. If so, it's not prime
**/
int isPrime(unsigned long long n){
    unsigned long long idx;
    for(idx = 2; idx < (n/2); idx++){
        if(n % idx == 0){
            return 0;
        }
    }
    return 1;

}
int main(){

    unsigned long long largest = 1;
    unsigned long long current = largest;
    // we can safely say that after the number 2 all prime numbers are odds, because the even ones are divisible by 2
    // we can test any number more than the square root rounding to floor
    while(current*current < GOAL){
        if(current % 2 == 1 && GOAL % current == 0 && isPrime(current) == 1){
            largest = current;
        }
        current++;
    }
    printf("largest is %llu", largest);
}
