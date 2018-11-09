#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int palindrome(char[], int);

int main()
{
    int first;
    int second;
    int firstFactor;
    int secondFactor;
    int multiplication;
    int biggest = 0;
    char mult[100];

    for (first = 1; first <= 999; first++) {
        for (second = 1; second <= 999; second++) {
            sprintf(mult,"%d" ,(first*second));
            if (palindrome(mult, strlen(mult)) == 1 && (first*second) > biggest) {
                firstFactor = first;
                secondFactor = second;
                multiplication = first * second;
                biggest = multiplication;
            }
        }
    }

    printf("Result = %i\n", multiplication);
    return EXIT_SUCCESS;
}

int palindrome(char str[100], int tam) {

    int originalSize = strlen(str);

    if (tam <= 1) {
        return 1;
    }
    else if (str[originalSize - tam] == str[tam - 1]) {
        return palindrome(str, tam - 1);
    }
    else {
        return 0;
    }
}
