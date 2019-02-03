#include<stdlib.h>
#include<stdio.h>
#include "constants.h"

#define LIMIT 1000

int getNumberOfLettersUnit(int i){
	switch(i){
		case 1:
			return ONE;
		case 2:
			return TWO;
		case 3:
			return THREE;
		case 4:
			return FOUR;
		case 5:
			return FIVE;
		case 6:
			return SIX;
		case 7:
			return SEVEN;
		case 8:
			return EIGHT;
		case 9:
			return NINE;
		case 10:
			return TEN;
		case 11:
			return ELEVEN;
		case 12:
			return TWELVE;
		case 13:
			return THIRTEEN;
		case 14:
			return FOURTEEN;
		case 15:
			return FIFTEEN;
		case 16:
			return SIXTEEN;
		case 17:
			return SEVENTEEN;
		case 18:
			return EIGHTEEN;
		case 19:
			return NINETEEN;
		default:
			return 0;
	}
}

int numberOfLettersDozen(int i){
	if(i < 20){
		return getNumberOfLettersUnit(i);
	}else{
		int units = i%10;
		int dozen = i/10;
		switch(dozen){
			case 2:
				return TWENTY + getNumberOfLettersUnit(units);
			case 3:
				return THIRTY + getNumberOfLettersUnit(units);
			case 4:
				return FOURTY + getNumberOfLettersUnit(units);
			case 5:
				return FIFTY + getNumberOfLettersUnit(units);
			case 6:
				return SIXTY + getNumberOfLettersUnit(units);
			case 7:
				return SEVENTY + getNumberOfLettersUnit(units);
			case 8:
				return EIGHTY + getNumberOfLettersUnit(units);
			case 9:
				return NINETY + getNumberOfLettersUnit(units);
			default:
				return 0;
		}
	}
}

int numberOfLettersHundreds(int i){
	int hundred = i/100;
	int dozen = i%100;

	int numberOfLettersofAND = 3;

	int sum = 0;

	switch(hundred){
		case 1:
			sum += ONE + HUNDRED;
			break;
		case 2:
			sum += TWO + HUNDRED;
			break;
		case 3:
			sum += THREE + HUNDRED;
			break;
		case 4:
			sum += FOUR + HUNDRED;
			break;
		case 5:
			sum += FIVE + HUNDRED;
			break;
		case 6:
			sum += SIX + HUNDRED;
			break;
		case 7:
			sum += SEVEN + HUNDRED;
			break;
		case 8:
			sum += EIGHT + HUNDRED;
			break;
		case 9:
			sum += NINE + HUNDRED;
			break;
	}

	if(dozen == 0){
		return sum;
	}else{
		return sum + numberOfLettersofAND + numberOfLettersDozen(dozen);
	}
}

int numberOfLetters(int i){
	if(i <= 10){
		return getNumberOfLettersUnit(i);
	}else if(i < 100){
		return numberOfLettersDozen(i);
	}else{
		return numberOfLettersHundreds(i);
	}
}

int main(){
	int i;
	int numberOfLettersOfONETHOUSAND = ONE + THOUSAND;
	int nol /* number of letters */ = 0;
	for(i = 1 ; i < LIMIT; i++){
		nol += numberOfLetters(i);
	}

	nol += numberOfLettersOfONETHOUSAND;
	printf("number of letters = %i\n", nol);
}