#include "stdlib.h"
#include "stdio.h"
#include<math.h>
#define GOAL 2000000

int isPrime(int n){
    long long i = 2;
    long long lim = (long long)sqrt(n);
    while((i <= lim) && (n % i != 0)){
        i++;
    }
    if((i-1) == lim) return 1;
    return 0;
}
int main(){
    long long sum = 5;
    long long n;
    for(n = 4; n < GOAL; n++){
        if(isPrime(n))
            sum += n;
    }
    printf("\nAnswer = %lld\n", sum);
}
