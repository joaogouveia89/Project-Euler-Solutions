#include <stdio.h>
#include <time.h>

long timediff(clock_t t1, clock_t t2) {
    long elapsed;
    elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
    return elapsed;
}

int main(void) {
    clock_t t1, t2;
    int i;
    float x = 2.7182;
    long elapsed;

    t1 = clock();
    for (i=0; i < 1000000; i++) {
           x = x * 3.1415;
    }
    t2 = clock();

    elapsed = timediff(t1, t2);
    printf("elapsed: %ld ms\n", elapsed);


    return 0;
}
