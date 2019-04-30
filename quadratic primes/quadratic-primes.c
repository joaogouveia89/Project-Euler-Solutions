#include<stdlib.h>
#include<stdio.h>
#include"../utils/numbercharacteristic.h"

#define MAX 1000

int numberOfConsecutivePrimes(int a, int b){
	int counter = 0;
	int n = 0;
	int ip = 1;
	while(ip == 1){
		ip = isPrime(n*n + a*n + b);
		n++;
		if(ip == 1)
			counter++;
	}
	return counter;
}

int main(int argc, char const *argv[])
{
	int nocp;
	int greattest = 1;
	int n, a, b;
	int product;
	for(a = 0; a < MAX; a++){
		for(b = 0; b <= MAX; b++){
			nocp = numberOfConsecutivePrimes(a, b);
			if(nocp > greattest){
				greattest = nocp;
				product = a * b;
			}
			nocp = numberOfConsecutivePrimes(a*-1, b);
			if(nocp > greattest){
				greattest = nocp;
				product = -a * b;
			}
			nocp = numberOfConsecutivePrimes(a, b * -1);
			if(nocp > greattest){
				greattest = nocp;
				product = a * -b;
			}
			nocp = numberOfConsecutivePrimes(a * -1, b * -1);
			if(nocp > greattest){
				greattest = nocp;
				product = -a * -b;
			}
		}
	}
	printf("%i\n", product);
	return 0;
}