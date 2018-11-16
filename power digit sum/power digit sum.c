#include<stdlib.h>
#include<stdio.h>
//for this problem I got the sum function for big numbers of large sum
/**
*  START OF LARGE SUM INSPIRED
*/
#define NEXT_DIGIT 51

#define NUMBER_OF_NUMBERS 100
#define NUMBERS_LENGHT 49

int charToInt(char c){
    switch(c){
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    }
}

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

void printFirst10(TList* list){
    int idx = 0;
    TList* aux = list;

    while(idx < 10 && aux != NULL){
        printf("%i",aux->n);
        aux = aux->next;
        idx++;
    }
    printf("\n");
}

void printAll(TList* list){
    TList* aux = list;

    while(aux != NULL){
        printf("%i",aux->n);
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

TList* popCarrie(TList* carrie){
    if(carrie != NULL){ //just for safety
        TList* aux = carrie;
        carrie = carrie->next;
        free(aux);
    }
    return carrie;
}

/**
* END OF LARGE SUM INSPIRED
*/
int main(){
    int currentNumber = 0;
    int currentDigit = NUMBERS_LENGHT;
    int sum = 0;

    TList* result = push_back(result, 2);
    TList* carrie = NULL;
    printf("teste");
}

