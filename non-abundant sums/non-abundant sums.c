#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#define PERFECT 2
#define DEFICIENT 3
#define ABUNDANT 4

#define MAX 28123 //By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers
#define MIN 12 // 12 is the smallest abundant number

typedef struct list TList;

struct list
{
	int number;
	TList* next;
};

TList* add(TList* list, int n){
	TList* aux = list;
	TList* new_node = (TList*) malloc(sizeof(TList));
	new_node->number = n;
	new_node->next = NULL;

	if(list == NULL){
		list = new_node;
	}else{
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = new_node;
	}
	return list;
}

int list_size(TList* list){
	TList* aux = list;
	int counter = 0;
	while(aux != NULL){
		counter++;
		aux = aux->next;
	}
	return counter;
}

void list_print(TList* list){
	TList* aux = list;
	printf("\n");
	while(aux != NULL){
		printf("%i, ", aux->number);
		aux = aux->next;
	}
	printf("\n");
}

unsigned int sum_divisors(unsigned int i){
	unsigned int checkLimit = sqrt(i);
	unsigned int num;
	unsigned int sum = 0;

	for(num = 1; num <= checkLimit; num++){
		if(i % num == 0){
			sum += num;
			if(i/num != num && i/num != i){
				sum += (i/num);
			}		
		}
	}
	return sum;
}

int num_classification(int n){
	int sum = sum_divisors(n);

	if(sum > n){
		return ABUNDANT;
	}else if(sum < n){
		return DEFICIENT;
	}else{
		return PERFECT;
	}
}

TList* get_abundant_numbers(TList* abundants){
	int i;
	for(i = MIN; i <= MAX; i++){
		if(num_classification(i) == ABUNDANT){
			abundants = add(abundants, i);
		}
	}
	return abundants;
}

unsigned int get_non_abundant_sum(TList* abundants){
	TList* interaction = abundants;
	TList* interaction1 = abundants;
	int isAbundantSum[MAX+1] = { 0 };
	unsigned int totalSum = 0;
	int i;

	while(interaction != NULL && (interaction->number + abundants->number) <= MAX){
		while(interaction1 != NULL && interaction1 != interaction->next && (interaction->number + interaction1->number) <= MAX){
			isAbundantSum[interaction->number + interaction1->number] = 1;
			interaction1 = interaction1->next;
		}
		interaction1 = abundants;
		interaction = interaction->next;
	}
	
	for(i = 0; i <= MAX; i++){
		if(isAbundantSum[i] == 0){
			totalSum += i;
		}
	}
	return totalSum;
}

int main(int argc, char const *argv[])
{
	//ANSWER = 4179871
	TList* abundants = NULL;
	unsigned int total = 0;
	int i;

	printf("Fetching all abundant numbers...\n");
	abundants = get_abundant_numbers(abundants);

	printf("Get non abundant sum...\n");
	total = get_non_abundant_sum(abundants);

	printf("sum = %i\n", total);
	return 0;
}
