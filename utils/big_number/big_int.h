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


BigInt* bi_mul_to_i(BigInt* bi, int times){
	UnsignedShortLinkedList* aux = bi->data;
    UnsignedShortLinkedList* finalResult = NULL;
    UnsignedShortLinkedList* carrie = NULL;
    int temp;
    while(aux != NULL){
        temp = aux->data * times;
        if(carrie != NULL){
            temp += carrie->data;
            carrie = bi_pop_carrie(carrie);
        }
        finalResult = usll_push_back(finalResult, temp%10);
        if(temp > 9){
            carrie = bi_generate_carrie(carrie, temp);
        }
        aux = aux->next;
    }
    //merging the rest of carrie to the result
    while(carrie != NULL){
        finalResult = usll_push_back(finalResult, carrie->data);
        carrie = bi_pop_carrie(carrie);
    }
    usll_free_list(bi->data);
    bi->data = finalResult;
    bi->size = usll_size(bi->data);
    return bi;
}

BigInt* int_pow_to_bi(int a, int b){
	int idx;
	BigInt* bi = NULL;

	bi = bi_init_with_data(a);
	for(idx = 0; idx < b; idx++){
		bi = bi_mul_to_i(bi, a);
	}
	return bi;
}

/*
* b1 < b2 ----- returns -1
* b1 = b2 ----- returns 0
* b1 > b2 ----- returns 1
*/
int bi_compare(BigInt* bi1, BigInt* bi2){
	UnsignedShortLinkedList* it1 = bi1->data;
	UnsignedShortLinkedList* it2 = bi2->data;
	int response;

	if(bi1->size > bi2->size){
		response =  1;
	}else if(bi1->size < bi2->size){
		response = -1;
	}else{
		response = 0;
		while(it1 != NULL && it2 != NULL){
			if(it1->data > it2->data){
				response = 1;
			}else if(it1->data < it2->data){
				response = -1;
			}
			it1 = it1->next;
			it2 = it2->next;
		}
	}

	return response;
}
#endif
