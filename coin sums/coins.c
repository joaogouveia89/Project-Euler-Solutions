#include<stdlib.h>
#include<stdio.h>
#define GOAL 200

/* using dynamic programming */
void incrementTimes(int *times, int sum){
        int idx = 0;
        if(sum <= GOAL){
                while(times[idx] > GOAL){
                        times[idx] = 0;
                        idx++;
                }
                times[idx]++;
        }else{
                while(times[idx] == 0){
                        idx++;
                }
                times[idx] = 0;
                times[idx+1]++;
        }
}

void print_arr(int* arr){
        int idx;
        for(idx = 0; idx < 7; idx++){
                printf("%i, ", arr[idx]);
        }
        printf("\n");
}

int main(){
        int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
        
        int coinsSize = sizeof(coins)/sizeof(int);
        int times[] = {0, 0, 0, 0, 0, 0, 0, 0};
        int sum = 0;
        int waysTo200 = 0;
        int idx;

        while((coins[coinsSize-1]*times[coinsSize-1]) <= GOAL){
                sum = 0;            
                for(idx = 0; idx < coinsSize; idx++){
                        sum += (coins[idx] * times[idx]);

                }
                if(sum == 200){
                        waysTo200++;                    
                }
                incrementTimes(&times[0], sum);               
        }
        printf("answer = %i\n", waysTo200);
}
