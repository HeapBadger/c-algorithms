/*
 *  Monte Carlo Simulation of Rolling 2 Unfair Dice
 *  author: Anna DeVries
 *  date: 18 February 2021	
 *
 *  gcc -c rng.c
 *  gcc -lm <file>.c rng.o -o <file> && ./<file>
 */

#include <stdio.h>
#include "rng.h"

#define N 10000L                          /* number of replications */


long Equilikely(long a, long b){ 
    return (a + (long) ((b - a + 1) * Random()));
}


int main(void){
    long   i;                               /* replication index        */
    long   d1, d2;                          /* two individual dice      */
    long   x;                               /* sum of two dice          */
    long   count[13] = {0};                 /* histogram                */
    double p[13]     = {0.0};               /* probability estimates    */

    PutSeed(0);

    for (i = 0; i < N; i++) {
        d1 = Equilikely(1, 13);
        d2 = Equilikely(1, 13);

        //  Create if statements for loaded dice 1
        if (d1 == 1)
            d1 = 1;
        else if (d1 > 1 & d1 < 4)
            d1 = 2;
        else if (d1 > 3 & d1 < 6)
            d1 = 3;
        else if (d1 > 5 & d1 < 8)
            d1 = 4;
        else if (d1 > 7 & d1 < 10)
            d1 = 5;
        else if (d1 > 9)
            d1 = 6;

        //  Create if statements for loaded dice 2
        if (d2 == 1)
            d2 = 1;
        else if (d2 > 1 & d2 < 4)
            d2 = 2;
        else if (d2 > 3 & d2 < 6)
            d2 = 3;
        else if (d2 > 5 & d2 < 8)
            d2 = 4;
        else if (d2 > 7 & d2 < 10)
            d2 = 5;
        else if (d2 > 9)
            d2 = 6;

        //  Sum dice
        x = d1 + d2;
        count[x]++;
    }

    for (x = 2; x < 13; x++)                /* estimate probabilities */
        p[x] = (double) count[x] / N;

    printf("\nbased on %ld replications ", N);
    printf("the estimated probabilities are:\n\n");
    for (x = 2; x < 13; x++)
        printf("p[%2ld] = %5.3f\n", x, p[x]);
    printf("\n");

    return (0);
}
