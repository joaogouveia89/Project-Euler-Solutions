#include<stdlib.h>
#include<stdio.h>
#define GRID_SIZE 20

// to make a little more faster, I would use circular double linked list
typedef struct List TList;

struct List{
    long long data;
    TList* next;
};

TList* new_node(long long data){
    TList* node = (TList*) malloc(sizeof(TList));
    node->data = data;
    node->next = NULL;
    return node;
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
    int currentGrid = 1;
    lastColumn = new_node(1);
    TList* aux_lc = NULL;
    TList* aux_cc = NULL;

    while(currentGrid <= GRID_SIZE){
             //columns always starts with only one way to reach the final point
            currentColumn = new_node(1);
            aux_lc = lastColumn;
            aux_cc = currentColumn;
            while(aux_lc->next != NULL){

                aux_cc->next = new_node(aux_cc->data + aux_lc->next->data);
                aux_lc = aux_lc->next;
                aux_cc = aux_cc->next;
            }
            aux_cc->next = new_node((aux_cc->data) * 2);
            lastColumn = drainOutList(lastColumn);
            lastColumn = copyList(currentColumn, lastColumn);
            currentGrid++;
    }
    aux_cc->next = new_node((aux_cc->data) * 2);
    aux_cc = aux_cc->next;
    printf("Answer = %lld", aux_cc->data);
}
