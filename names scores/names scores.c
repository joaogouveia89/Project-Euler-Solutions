#include <stdlib.h>
#include<stdio.h>
#define FILE_NAME "p022_names.txt"

typedef struct model_word String;
typedef struct list TList;

struct model_word{
    char c;
    String* nextLetter;
};


struct list{
    String* word;
    TList* next;
    TList* previous;
};


/*
* STRING FUNCTIONS
*/

String* str_add_char(String* name, char c){
	String* newChar = (String*) malloc(sizeof(String));
	newChar->c = c;
	newChar->nextLetter = NULL;

	if(name == NULL){
		name = newChar;
	}else{
		String* aux = name;
		while(aux->nextLetter != NULL){
			aux = aux->nextLetter;
		}
		aux->nextLetter = newChar;
	}

	return name;
}

void str_print(String* str){
	String* aux = str;

	while(aux != NULL){
		printf("%c",aux->c);
		aux = aux->nextLetter;
	}
}

/*
* return values:
* -1: fst < snd
* 0 : fst = snd
* 1 : fst > snd
*/
int compare(String* fst, String* snd){
	String* itfst = fst;
	String* itsnd = snd;

	if(fst == NULL && snd == NULL){
		return 0;
	}else if(fst == NULL){
		return -1;
	}else if(snd == NULL){
		return 1;
	}

	while(itfst != NULL && itsnd != NULL){
		if(itfst->c > itsnd->c){
			return 1;
		}else if(itfst->c < itsnd->c){
			return -1;
		}
		itfst = itfst->nextLetter;
		itsnd = itsnd->nextLetter;
	}

	if(itfst == NULL && itsnd != NULL){
		return -1;
	}else if(itfst != NULL && itsnd == NULL){
		return 1;
	}

	return 0;
}

/*
* LIST FUNCTIONS
*/

TList* add(TList* list, String* word){
	TList* element = (TList*) malloc(sizeof(TList));
	element->word = word;
	element->next = NULL;
	element->previous = NULL;

	if(list == NULL){
		list = element;
	}else{
		TList* aux = list;
		while(aux->next != NULL){
			aux = aux->next;
		}
		element->previous = aux;
		aux->next = element;
	}

	return list;
}

void list_print(TList* list){
	TList* aux = list;

	while(aux != NULL){
		str_print(aux->word);
		aux = aux->next;
		printf("\n");
	}
}

void debug_list(TList* list){
	int node = 1;

	TList* aux = list;

	while(aux != NULL){
		printf("\n------------- NODE %i -------------\n", node);
		printf("previous = ");
		if(aux->previous == NULL) printf("NULL"); else str_print(aux->previous->word);
		printf("\ncontent = ");
		str_print(aux->word);
		printf("\nnext = ");
		if(aux->next == NULL) printf("NULL"); else str_print(aux->next->word);
		node++;
		aux = aux->next;
	}
	printf("\n");
}


TList* get_names(TList* list){
	char fileChar;
	FILE* fp = NULL;
	int openedQuotes = 0;
	String* name = NULL;
	TList* names = NULL;

	fp = fopen(FILE_NAME, "r");

	if(fp == NULL){
		perror("Error while opening the file!");
		exit(EXIT_FAILURE);
	}
	// not validating the file for messy and uncleaned inputs
	while((fileChar = fgetc(fp)) != EOF){
		if(fileChar == '\"'){
			if(openedQuotes == 0){
				openedQuotes = 1;
			}else{
				openedQuotes = 0;
			}			
		}else{
			// it works because of the comma char
			if(openedQuotes == 1){
				name = str_add_char(name, fileChar);
			}else{
				names = add(names, name);
				name = NULL;

			}
		}
	}
	names = add(names, name);
	return names;
}

int list_size(TList* list){
	TList* aux = list;
	int counter = 0;

	while(aux != NULL){
		aux = aux->next;
		counter++;
	}

	return counter;
}

TList* find(TList* list, int position){
	int cur = 1;
	TList* match = list;

	while(match != NULL && cur < position){
		match = match->next;
		cur++;
	}

	return match;
}

TList* swap(TList* list, int from, int to){
	TList* aux = list;
	TList* aux2 = NULL;
	TList* toList = NULL;
	TList* fromList = NULL;
	int sizeList = list_size(list);

	int idx = 1;

	if(from >= to || to > sizeList || from < 0) return list;

	while(idx <= to){
		if(idx == from){
			fromList = aux;
		}
		if(idx == to){
			toList = aux;
		}
		idx++;
		aux = aux->next;
	}

	if(toList != NULL && fromList != NULL){
		//adjacent case
		//"MARY","PATRICIA","LINDA","BARBARA","ELIZABETH","JENNIFER","MARIA"
		if(fromList->next == toList){
			//as they are adjacents toList->previous = fromList so fromList->next = toList the same rule to fromList->next
			if(from != 1){
				fromList->previous->next = toList;
			}else{
				list = toList;
			}
			
			if(to != sizeList){
				toList->next->previous = fromList;
			}
			
			aux = fromList->previous;
			fromList->previous = toList;
			toList->previous = aux;

			fromList->next = toList->next;
			toList->next = fromList;

		}/* non adjacent case */else{
			toList->previous->next = fromList;
			if(from != 1){
				fromList->previous->next = toList;
			}else{
				list = toList;
			}
			if(to != sizeList){
				toList->next->previous = fromList;
			}			
			fromList->next->previous = toList;

			aux = fromList->previous;
			fromList->previous = toList->previous;
			toList->previous = aux;

			aux = fromList->next;
			fromList->next = toList->next;
			toList->next = aux;			
		}
	}
	return list;
}



//quick sort
TList* sort(TList* list, int first,int last){
   int i, j, pivot, compareToPivot;
   TList* temp = NULL;
   TList* listi = NULL;
   TList* listj = NULL;
   TList* listPivot = NULL;
   int size = list_size(list);

   if(first < last){
      i = first + 1;
      j = last;

      if(i > 0 && i <= size) listi = find(list, i);
      if(j > 0 && j <= size) listj = find(list, j);

      if(first > 0 && first <= size) listPivot = find(list, first);

      while(i <= j){
         if(listi != NULL && listPivot != NULL && compare(listi->word, listPivot->word) <= 0){
           	i++;
           	listi = listi->next;
         }
         else if(listj != NULL && listPivot != NULL && compare(listj->word, listPivot->word) == 1){
         	j--;
         	listj = listj->previous;
         }
         else if(i <= j){
         	list = swap(list, i, j);
         	i++;
         	/**
         	* TODO: FIND A WAY TO REMOVE THESE 2 FINDS FUNCTION TO IMPROVE PERFORMANCE, SIMPLY PUTTING listi->next and listij->previous DOESN'T WORK, DON'T KNOW WHY
         	*/
         	if(i > 0 && i <= size) listi = find(list, i);
         	j--;
         	if(j > 0 && j <= size) listj = find(list, j);
         }
      }
      list = swap(list, first, j);
      list = sort(list, first, j-1);
      list = sort(list, j+1, last);
   }
   return list;
}



int main(int argc, char const *argv[])
{
	TList* names = NULL;

	names = get_names(names);
	int size = list_size(names);
	names = sort(names, 1,  size);
	list_print(names);

	return 0;
}