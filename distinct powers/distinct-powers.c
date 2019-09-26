#include <stdlib.h>
#include <stdio.h>
#include "../utils/linked_lists/big_int_linked_list.h"

int main(int argc, char const *argv[])
{
	BigInt* number = NULL;
	BigInt* number2 = NULL;
	number = bi_init_with_data(102);
	number2 = bi_init_with_data(100);

	int n = bi_compare(number2, number);

	printf("%i\n", n);
	return 0;
}