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
	bi->data = usll_init(bi->data, n);
	bi->size = usll_size(bi->data);
	return bi;
}

void bi_print(BigInt* root){
	usll_print_together(root->data);
}

UnsignedShortLinkedList* bi_generate_carrie(UnsignedShortLinkedList* carrie, int sum){
    int sum1 = sum/10;
    UnsignedShortLinkedList* aux = carrie;
    UnsignedShortLinkedList* last = NULL;
    while(sum1 > 0){
        if(aux == NULL){
            aux = (UnsignedShortLinkedList*) malloc(sizeof(UnsignedShortLinkedList));
            aux->data = sum1%10;
            if(last != NULL) last->next = aux;
            aux->next = NULL;
            if(carrie == NULL) carrie = aux;
        }else{
            if((aux->data + sum1%10) > 9){
                int sum2 = (aux->data + sum1%10);
                aux->data = (aux->data + sum1%10) % 10;
                aux->next = bi_generate_carrie(aux->next, sum2);
            }else{
                aux->data = (aux->data + sum1%10);
            }
        }
        last = aux;
        aux = aux->next;
        sum1 /= 10;
    }
    return carrie;
}

UnsignedShortLinkedList* bi_pop_carrie(UnsignedShortLinkedList* carrie){
    if(carrie != NULL){ //just for safety
        UnsignedShortLinkedList* aux = carrie;
        carrie = carrie->next;
        free(aux);
    }
    return carrie;
}

BigInt* bi_sum_int(BigInt* bi, int n){
	
}


#endif
