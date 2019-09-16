#include <stdlib.h>
#include <stdio.h>
#include "../utils/big_number/big_int.h"

int main(int argc, char const *argv[])
{
	BigInt* number = NULL;
	unsigned short a, b;

	number = bi_init_with_data(2);

	number = bi_mul_to_i(number, 50);
	usll_print_together(number->data);
	return 0;
}