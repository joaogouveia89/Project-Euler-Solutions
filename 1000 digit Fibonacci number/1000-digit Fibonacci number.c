#include<stdlib.h>
#include<stdio.h>

#define DIGIT_GOAL 1000

typedef struct list TList;

struct list{
    int n;
    TList* next;
};


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


TList* push_front(TList* list, int number){
    TList* aux = (TList*) malloc(sizeof(TList));
    aux->n = number;
    aux->next = list;
    return aux;
}

void printList(TList* list){
    TList* aux = list;
    while(aux != NULL){
        printf("%i", aux->n);
        aux = aux->next;
    }
    printf("\n");
}


void printListReverse(TList* list){
    TList* aux = list;
    TList* reverse = NULL;
    while(aux != NULL){
        reverse = push_front(reverse, aux->n);
        aux = aux->next;
    }
    aux = reverse;
    while(aux != NULL){
    	printf("%i", aux->n);
    	aux = aux->next;
    }
    printf("\n");
}

TList* generateCarrie(TList* carrie, int sum){
    int sum1 = sum/10;
    TList* aux = carrie;
    TList* last = NULL;
    while(sum1 > 0){
        if(aux == NULL){
            aux = (TList*) malloc(sizeof(TList));
            aux->n = sum1%10;
            if(last != NULL) last->next = aux;
            aux->next = NULL;
            if(carrie == NULL) carrie = aux;
        }else{
            if((aux->n + sum1%10) > 9){
                int sum2 = (aux->n + sum1%10);
                aux->n = (aux->n + sum1%10) % 10;
                aux->next = generateCarrie(aux->next, sum2);
            }else{
                aux->n = (aux->n + sum1%10);
            }
        }
        last = aux;
        aux = aux->next;
        sum1 /= 10;
    }
    return carrie;
}

TList* merge(TList* from, TList* to){
	TList* aux = from;
	while(aux->next != NULL){
		aux = aux->next;
	}
	aux->next = to;
	return from;
}

TList* popCarrie(TList* carrie){
    if(carrie != NULL){ //just for safety
        TList* aux = carrie;
        carrie = carrie->next;
        free(aux);
    }
    return carrie;
}

TList* setValue(TList* number, int i){
	int div = 1;

	while(i/div != 0){
		div *= 10;
		number = push_front(number, i % div);
	}

	return number;
}

void cleanMemory(TList* list){
	TList* aux = list;
	if(list != NULL){
		while(aux != NULL){
			list = aux;
			aux = aux->next;
			free(list);
		}
	}
}



int main(int argc, char const *argv[])
{
	TList* current = NULL;
	TList* last = NULL;

	TList* itCurrent = NULL;
	TList* itLast = NULL;

	TList* carrie = NULL;

	TList* result = NULL;

	int numberOfDigits = 1;
	int sum;

	/**
	*initializing numbers
	*/
	current = setValue(current, 1);
	last 	= setValue(last, 1);
	int it = 2; // as we already have 2 members of the fibonacci sequence

	while(numberOfDigits != DIGIT_GOAL){
		itCurrent = current;
		itLast = last;
		result = NULL;
		while(itCurrent != NULL && itLast != NULL){
			sum = itCurrent->n + itLast->n;

			if(carrie != NULL){
	            sum += carrie->n;
	            carrie = popCarrie(carrie);
	        }

	        result = push_back(result, sum%10);
        	carrie = generateCarrie(carrie, sum);

			itCurrent = itCurrent->next;
			itLast = itLast->next;
		}

		while(itCurrent != NULL){
			if(carrie == NULL){
				result = push_back(result, itCurrent->n);
			}else{
				result = push_back(result, itCurrent->n + carrie->n);
				carrie = popCarrie(carrie);
			}			
			itCurrent = itCurrent->next;
		}

		while(carrie != NULL){
			numberOfDigits++;
			result = push_back(result, carrie->n);
			carrie = popCarrie(carrie);
		}

		cleanMemory(last);

		last = current;
		current = result;
		it++;
	}
	printf("Answer = %i\n", it);
	return 0;
}