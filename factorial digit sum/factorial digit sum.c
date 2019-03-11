#include<stdlib.h>
#include<stdio.h>

#define FACTORIAL 100

typedef struct list TList;

struct list{
    int n;
    TList* next;
};

void printList(TList* list){
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

TList* push_front(TList* list, int number){
    TList* aux = (TList*) malloc(sizeof(TList));
    aux->n = number;
    aux->next = list;
    return aux;
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

TList* popCarrie(TList* carrie){
    if(carrie != NULL){ //just for safety
        TList* aux = carrie;
        carrie = carrie->next;
        free(aux);
    }
    return carrie;
}

void freeList(TList* root){
    TList* aux = root->next;
    while(root != NULL){
        free(root);
        root = aux;
        if(aux != NULL){
            aux = aux->next;
        }        
    }
}

int sumList(TList* list){
    int sum = 0;
    TList* aux = list;
    while(aux != NULL){
        sum += aux->n;
        aux = aux->next;
    }

    return sum;
}

TList* multiply(TList* number, int times){
	TList* aux = number;
    TList* finalResult = NULL;
    TList* carrie = NULL;
    int temp;
    while(aux != NULL){
        temp = aux->n * times;
        if(carrie != NULL){
            temp += carrie->n;
            carrie = popCarrie(carrie);
        }
        finalResult = push_back(finalResult, temp%10);
        if(temp > 9){
            carrie = generateCarrie(carrie, temp);
        }
        aux = aux->next;
    }
    //merging the rest of carrie to the result
    while(carrie != NULL){
        finalResult = push_back(finalResult, carrie->n);
        carrie = popCarrie(carrie);
    }
    freeList(number);
    return finalResult;
}

void printAll(TList* list){
    TList* aux = list;

    while(aux != NULL){
        printf("%i",aux->n);
        aux = aux->next;
    }
    printf("\n");
}


int main(){
	TList* number = NULL;

	number = push_front(number, 1);

	int mul;

	for(mul = 1; mul <= FACTORIAL; mul++){
		number = multiply(number, mul);
	}

	printf("answer = %i\n", sumList(number));

}