#include <stdlib.h>
#include <stdio.h>
#include "../utils/big_number/big_int.h"

int main(int argc, char const *argv[])
{
	BigInt* number = NULL;

	number = bi_init_with_data(2);
	bi_print(number);
	return 0;
}