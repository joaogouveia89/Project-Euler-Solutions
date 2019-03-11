#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "list.h"

#define FILE_NAME "data.txt"

int char_to_int(char c){
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

TList* get_list_from_file(TList* data){
	char fileChar;
	FILE* fp = NULL;
	int number = 0;

	fp = fopen(FILE_NAME, "r");

	if(fp == NULL){
		perror("Error while opening the file!");
		exit(EXIT_FAILURE);
	}
	// not validating the file for messy and uncleaned inputs
	while((fileChar = fgetc(fp)) != EOF){
		if(fileChar != '\n' && fileChar != ' ' && fileChar != EOF){
			number  = (number * 10) + char_to_int(fileChar);
		}else{
			data = push_front(data, number);
			number = 0;
		}
	}
	data = push_front(data, number);
	fclose(fp);
	return data;
}

int get_number_of_lines(TList* triangle){
	int counter = 0;
	int numberOfLines;
	TList* aux = triangle;
	if(triangle == NULL){
		return -1;
	}

	while(aux != NULL){
		counter++;
		aux = aux->next;
	}

	// 2th degree equation root calculus an² + bn + c = 0 where a = 1 b = 1 c = ? 
	int c = counter * 2 * (-1);

	numberOfLines = (-1 + sqrt(1 - 4*c))/2;
	if(numberOfLines < 0){
		numberOfLines = (-1 - sqrt(1 - 4*c))/2;
	}

	return numberOfLines;
}


int maximum_path_sum(TList* triangle){
	//starting in the last line
	int currentLine = get_number_of_lines(triangle);
	int sum = -1;
	TList* iteratorParent = triangle;
	TList* iteratorChildren = triangle;
	int ref = 0;

	while(ref < currentLine){
		iteratorParent = iteratorParent->next;
		ref++;
	}
	ref = 1;
	while(iteratorParent != NULL){
		if(ref == currentLine){
			iteratorChildren = iteratorChildren->next;
			ref = 1;
			currentLine--;
		}
		if(iteratorChildren->data > iteratorChildren->next->data){
			iteratorParent->data = iteratorParent->data + iteratorChildren->data;
		}else{
			iteratorParent->data = iteratorParent->data + iteratorChildren->next->data;
		}
		sum = iteratorParent->data;
		ref++;
		iteratorParent = iteratorParent->next;
		iteratorChildren = iteratorChildren->next;
	}
	return sum;
}

int main(){
	TList* triangle = get_list_from_file(triangle);	
	int mps = maximum_path_sum(triangle);
	printf("answer = %i\n", mps);
}
 
	