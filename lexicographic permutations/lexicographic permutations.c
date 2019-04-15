/**
* IF WE GET THE NUMBERS START WITH 0 WE HAVE 362880 LEXOGRAPHIC NUMBERS IN THIS INTERVAL AS WE CAN SEE:
* '0' 9 x 8 x 7 x 6 x 5 x 4 x 3 x 2 x 1 = 362880
* FOR NUMBERS STARTING WITH 1 WE HAVE MORE 362880 POSSIBILITIES SO WE HAVE 725760 NUMBERS BEWTEEN 0123456789 AND 1987654320
* FOR NUMBERS STARTING WITH 2 WE HAVE MORE 362880 POSSIBILITIES SO WE HAVE 1088640 POSSIBITIES BETWEEN 0123456789 AND 298765431
* SO IT IS CLEAR THAT THE NUMBER 1000000 STARTS WITH 2... GOING ON THIS ANALISYS AND REDUCING THE RANGE WE CAN REACH THE RESULT...

* THIS IS THE HAND WAY I FOUND TO SOLVE, AND THIS ONE IS THE ALGORITHM ONE BASED IN THIS ARCTICLE
* http://bearcave.com/random_hacks/permute.html
**/

#include<stdlib.h>
#include<stdio.h>

#define SIZE 10
#define DESIRED_POSITION 1000000

void print(int* permutation){
	int i;
	for(i = 0; i < SIZE; i++){
		printf("%i", permutation[i]);
	}
	printf("\n");
}

void swap(int* permutation, int i, int j){
	int t;
	t = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = t;
}

void rotateLeft(int* permutation, int start, int n){
	int tmp = permutation[start];
	int i;
	for(i = start; i < n - 1; i++){
		permutation[i] = permutation[i + 1];
	}
	permutation[n - 1] = tmp;
}

void permute(int* permutation, int start, int n, int* permutationPosition){
	int i, j;
	int tmp;
	if(*permutationPosition == DESIRED_POSITION){
		print(permutation);
	}
	*permutationPosition = *permutationPosition + 1;
	if(start < n && ((*permutationPosition) - 1) != DESIRED_POSITION){
		
		for(i = n - 2; i >= start; i--){
			for(j = i + 1; j < n; j++){
				swap(permutation, i, j);
				permute(permutation, i + 1, n, permutationPosition);
			}
			rotateLeft(permutation, i, n);
		}
	}
	
}

int main(){
	int permutation[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int permutationPosition = 1;
	permute(permutation, 0, SIZE, &permutationPosition);
}