#include <stdlib.h>
#include<stdio.h>

#define LIMIT 10000

typedef struct list TList;

struct list{
    int n;
    TList* next;
};

void print_list(TList* list){
    TList* aux = list;
    while(aux != NULL){
        printf("%i, ", aux->n);
        aux = aux->next;
    }
}

TList* push_back(TList* list, int number){
    TList* aux = (TList*) malloc(sizeof(TList));
    aux->n = number;
    aux->next = NULL;
    if(list == NULL){
        list = aux;
    }else{
        TList* aux2 = list;
        while(aux2->next != NULL){
            aux2 = aux2->next;
        }
        aux2->next = aux;
    }

    return list;
}

int sum_list(TList* list){
    int sum = 0;
    TList* aux = list;
    while(aux != NULL){
        sum += aux->n;
        aux = aux->next;
    }

    return sum;
}


unsigned int sum_divisors(unsigned int i){
	unsigned int checkLimit = i/2;
	unsigned int num;
	unsigned int sum = 1;

	for(num = 2; num <= checkLimit; num++){
		if(i % num == 0){
			sum += num;
		}
	}
	return sum;
}

int has_been_tested(TList* list, int n){
	TList* aux = list;
	while(aux != NULL){
		if(aux->n == n){
			return 1;
		}
		aux = aux->next;
	}
	return 0;
}

int main(){
	unsigned int n;
	TList* list = NULL;

	int sumDivisors;
	int sumDivisorsOfSumDivisors;
	int sum;

	for(n = 1; n < LIMIT; n++){
		sumDivisors = sum_divisors(n);		
		if (sumDivisors < LIMIT && n != sumDivisors && has_been_tested(list, n) == 0){
			sumDivisorsOfSumDivisors = sum_divisors(sumDivisors);
			if(sumDivisorsOfSumDivisors == n){
				list = push_back(list, n);
				list = push_back(list, sumDivisors);
			}
		}
	}

	sum = sum_list(list);
	printf("sum = %i\n", sum);
}