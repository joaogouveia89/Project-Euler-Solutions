#include<stdlib.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
	int sum = 1;
	int currentNumber = 1;
	int currentSize = 1;
	int sumRatio = 2;
	int n = 0;

	while(currentSize < 1001){
		while(n < 4){
			currentNumber+=sumRatio;
			sum += currentNumber;
			n++;
		}		
		sumRatio += 2;
		currentSize += 2;
		n = 0;
	}
	printf("%i\n", sum);
	return 0;
}