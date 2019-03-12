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
* LIST FUNCTIONS
*/

TList* add(TList* list, String* word){
	TList* element = (TList*) malloc(sizeof(TList));
	element->word = word;
	element->next = NULL;

	if(list == NULL){
		list = element;
	}else{
		TList* aux = list;
		while(aux->next != NULL){
			aux = aux->next;
		}
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

TList* sort(TList* list){
	
}

int main(int argc, char const *argv[])
{
	TList* names = NULL;

	names = get_names(names);

	list_print(names);

	return 0;
}