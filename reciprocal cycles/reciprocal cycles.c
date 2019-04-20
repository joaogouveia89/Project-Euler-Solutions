#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"../utils/numbercharacteristic.h"
#include"../utils/arithmetic.h"

#define ROOF 1000

/**A fraction in lowest terms with a prime denominator other than 2 or 5 (i.e. coprime to 10)
 always produces a repeating decimal. The length of the repetend (period of the repeating decimal
 segment) of 1/p is equal to the order of 10 modulo p. If 10 is a primitive root modulo p, the
 repetend length is equal to p − 1; if not, the repetend length is a factor of p − 1. This result
 can be deduced from Fermat's little theorem, which states that 10p−1 ≡ 1 (mod p).
 font: https://en.wikipedia.org/wiki/Repeating_decimal
*/

int main(int argc, char const *argv[])
{
	int greattest = 0;
	int greattestN;
	int n;
	int o;
	for(n = 6; n < ROOF; n++){
		if(isPrime(n) == PRIME){
			o = order(10, n);
			if(o > greattest){
				greattestN = n;
				greattest = o;
			}
		}
		
	}

	printf("answer = %i\n", greattestN);
	return 0;
}