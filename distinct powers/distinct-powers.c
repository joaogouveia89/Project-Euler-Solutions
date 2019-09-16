#include <stdlib.h>
#include <stdio.h>
#include "../utils/big_number/big_int.h"

int main(int argc, char const *argv[])
{
	BigInt* number = NULL;
	unsigned short a, b;

	number = bi_init_with_data(2);
	printf("%i\n", number->size);
	return 0;
}