#ifndef BIG_INT_H
#define BIG_INT_H
#include "../linked_lists/unsigned_short_linked_list.h"

typedef struct bi BigInt;

struct bi
{
	UnsignedShortLinkedList* data;
	int size;
};

BigInt* bi_init(){
	BigInt* bi = (BigInt*) malloc(sizeof(BigInt));
	bi->data = NULL;
	bi->size = 0;
	return bi;
}

BigInt* bi_init_with_data(int n){
	BigInt* bi = (BigInt*) malloc(sizeof(BigInt));
	bi->size = 0;
	bi->data = usll_init(bi->data, n);
	return bi;
}

void bi_print(BigInt* root){
	usll_print_together(root->data);
}


#endif
