#ifndef NUMBERCHARACTERISTIC_H
#define NUMBERCHARACTERISTIC_H
#include<math.h>

#define PRIME 1
#define NON_PRIME 0

int isPrime(int n){
    long i = 2;
    long lim = (long)sqrt(n);
    while((i <= lim) && (n % i != 0)){
        i++;
    }
    if((i-1) == lim) return PRIME;
    return NON_PRIME;
}

#endif