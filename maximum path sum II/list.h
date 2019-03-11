#ifndef LIST_H
#define LIST_H 
typedef struct List TList;

struct List
{
	int data;
	TList* next;
};

TList* push_front(TList* root, int data){
	TList* newNode = (TList*) malloc(sizeof(TList));
	newNode->next = root;
	newNode->data = data;

	return newNode;
}

void print_list(TList* root){
	TList* aux = root;
	while(aux != NULL){
		printf("%i\n", aux->data);
		aux = aux->next;
	}
}

#endif