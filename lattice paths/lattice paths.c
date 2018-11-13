#include<stdlib.h>
#include<stdio.h>
#define GRID_SIZE 6

// to make a little more faster, I would use circular double linked list
typedef struct List TList;

struct List{
    int data;
    TList* next;
};

TList* push_back(TList* root, int data){
    TList* aux = (TList*) malloc(sizeof(TList));
    aux->next = NULL;
    aux->data = data;

    if(root == NULL){
        root = aux;
    }else{
        TList* aux1 = root;
        while(aux1->next != NULL){
            aux1 = aux1->next;
        }
        aux1->next = aux;
    }

    return root;
}

TList* drainOutList(TList* root){
    TList* last = root;
    TList* next = root;
    while(next != NULL){
        next = last->next;
        free(last);
        last = next;
    }
    free(last);
    return next;
}

TList* copyList(TList* from, TList* to){
    to = from;
    return to;
}

void printList(TList* root){
    TList* aux = root;
    while(aux != NULL){
        printf("%i ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

int main(){
    TList* currentColumn = NULL;
    TList* lastColumn = NULL;
    int currentGrid = 0;
    lastColumn = push_back(lastColumn, 1);

    while(currentGrid < GRID_SIZE){
        currentGrid++;
    }
    printf("hello");
}
