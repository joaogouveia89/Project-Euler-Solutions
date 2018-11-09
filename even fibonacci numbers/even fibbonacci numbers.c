#include <stdlib.h>
#include <stdio.h>
#define MAX_VALUE 4000000
int main(){
    unsigned int sum = 1;
    unsigned int last = 1; // first term
    unsigned int current = 1; // second term
    unsigned int aux;

    while( current < MAX_VALUE){
        if(current % 2 == 1){
            sum += current;
        }
        aux = current;
        current += last;
        last = aux;
    }

    printf("sum = %i\n", sum );
}
