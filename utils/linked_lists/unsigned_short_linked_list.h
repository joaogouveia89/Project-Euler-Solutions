#ifndef UNSIGNED_SHORT_LINKED_LIST_H
#define UNSIGNED_SHORT_LINKED_LIST_H

/*
*	LIST FOR NUMBERS BETWEEN 0 AND 65535
*/
typedef struct usll UnsignedShortLinkedList;

struct usll
{
	unsigned short data;
	UnsignedShortLinkedList* next;
};


UnsignedShortLinkedList* usll_push_back(UnsignedShortLinkedList* root, unsigned short data){
	UnsignedShortLinkedList* newData = (UnsignedShortLinkedList*) malloc(sizeof(UnsignedShortLinkedList));
	newData->data = data;
	newData->next = NULL;

	if(root == NULL){
		root = newData;
	}else{
		UnsignedShortLinkedList* aux = root;
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = newData;
	}

	return root;
}

UnsignedShortLinkedList* usll_push_front(UnsignedShortLinkedList* root, unsigned short data){
	UnsignedShortLinkedList* newData = (UnsignedShortLinkedList*) malloc(sizeof(UnsignedShortLinkedList));
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

void usll_print_separated(UnsignedShortLinkedList* list){
	UnsignedShortLinkedList* aux = list;
	while(aux != NULL){
		printf("%i ", aux->data);
		aux = aux->next;
	}
	printf("\n");
}

void usll_print_together(UnsignedShortLinkedList* list){
	UnsignedShortLinkedList* aux = list;
	while(aux != NULL){
		printf("%i", aux->data);
		aux = aux->next;
	}
	printf("\n");
}


/*
* This method includes the element, ordering the list in asc order
* algorithm based on https://www.geeksforgeeks.org/given-a-linked-list-which-is-sorted-how-will-you-insert-in-sorted-way/
*/
UnsignedShortLinkedList* usll_add_in_asc_order(UnsignedShortLinkedList* root, unsigned short n){
	UnsignedShortLinkedList* newItem = (UnsignedShortLinkedList*) malloc(sizeof(UnsignedShortLinkedList));
	newItem->data = n;
	newItem->next = NULL;

	UnsignedShortLinkedList* aux = root;

	if(root == NULL){
		root = newItem;
	}else if(aux->data > n){
		newItem->next = aux;
		root = newItem;
	}else{
		while(aux->next != NULL && aux->next->data < newItem->data){
			aux = aux->next;
		}
		if(aux->next == NULL){
			aux->next = newItem;
		}else if(aux->next->data != n){
			newItem->next = aux->next;
			aux->next = newItem;
		}else{
			free(newItem);
		}
	}

	return root;
}

UnsignedShortLinkedList* usll_init(UnsignedShortLinkedList* root, int n){
	int div, remain;
	div = n;

	while(div != 0){
		remain = div %10;
		root = usll_push_front(root, remain);
		div /= 10;
	}
	return root;
}

int usll_size(UnsignedShortLinkedList* root){
	UnsignedShortLinkedList* aux = root;
	int size = 0;
	while(aux != NULL){
		size++;
		aux = aux->next;
	}
	return size;
}

void usll_free_list(UnsignedShortLinkedList* root){
    UnsignedShortLinkedList* aux = root->next;
    while(root != NULL){
        free(root);
        root = aux;
        if(aux != NULL){
            aux = aux->next;
        }
    }
}


#endif