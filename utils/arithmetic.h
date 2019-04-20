#ifndef ARITHMETIC_H
#define ARITHMETIC_H

int mdc(int a, int b){
	if(b == 0)
		return a;
	else
		return mdc(b, a % b);
}

int order(int a, int n){
	// https://www.geeksforgeeks.org/multiplicative-order/
	unsigned int result = 1;   
    int k = 1 ; 
	if(mdc(a, n) == 1){
		while (k < n) 
	    { 
	        result = (result * a) % n;
	        if (result  == 1) 
	            return k; 
	        k++; 
	    } 
	}
	return -1;
}

#endif