#ifndef BIG_INT_LINKED_LIST_H
#define BIG_INT_LINKED_LIST_H
#include "../big_number/big_int.h"

/*
*	LIST FOR NUMBERS BETWEEN 0 TO THE SIZE OF THE MEMORY STANDS
*/
typedef struct bill BigIntLinkedList;

struct bill
{
	BigInt* data;
	BigIntLinkedList* next;
};


BigIntLinkedList* bill_push_back(BigIntLinkedList* root, BigInt* data){
	BigIntLinkedList* newData = (BigIntLinkedList*) malloc(sizeof(BigIntLinkedList));
	newData->data =  data;
	newData->next = NULL;

	if(root == NULL){
		root = newData;
	}else{
		BigIntLinkedList* aux = root;
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = newData;
	}

	return root;
}

BigIntLinkedList* bill_push_front(BigIntLinkedList* root, BigInt* data){
	BigIntLinkedList* newData = (BigIntLinkedList*) malloc(sizeof(BigIntLinkedList));
	newData->data = data;
	newData->next = NULL;

	if(root == NULL){
		root = newData;
	}else{
		newData->next = root;
		root = newData;
	}
	return root;
}


int bill_size(BigIntLinkedList* root){
	BigIntLinkedList* aux = root;
	int size = 0;
	while(aux != NULL){
		size++;
		aux = aux->next;
	}
	return size;
}

#endif