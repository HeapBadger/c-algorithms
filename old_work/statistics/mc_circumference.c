/*
 *	Monte Carlo Simulation Circumference Problem
 *	author: Anna DeVries
 *	date: 18 February 2021
 *
 *  gcc -c rng.c
 *  gcc -lm <file>.c rng.o -o <file> && ./<file>
 *	
 *	Selects two random points on the circumference of a cirlce. It then calculates the distances between the points and compares it to the circle's radius. 
 *
 */

//	Libraries
#include <stdio.h>
#include "rng.h"
#include <math.h>

//	Macros
#define N   	10000L                          	/*  number of replications  */
#define PI  	3.13159265                      	/*  estimated value of pi   */
#define DEBUG 	0									/*	debugging value			*/

//	Uniform Distribution
double Uniform(double a, double b){                                         
  return (a + (b - a) * Random());    
}

//	Main Function
int main(void){
    //  Circle Information
    double alpha  = 0;                      		/*  x-xis center                */
    double beta   = 0;                      		/*  y-axis center               */
    double rho    = 10;                      		/*  radius                      */

    //  Variables for x and y
    double  x1;                              		/* x-axis point 1               */
    double  y1;                              		/* y-axis point 1               */
    double  x2;                              		/* x-axis point 2               */
    double  y2;                              		/* y-axis point 2               */
    double  phi1;                            		/* random angle phi             */
    double  phi2;                            		/* random angle phi             */
    double  distance;                        		/* distance between points      */

    //  Probability 
    long    count = 0;                       		/* counts when dist > rho       */
    long    i;                               		/* replication index            */

    PutSeed(0);

    for (i = 0; i < N; i++) {
        //  Randomly chosen x- and y-axis circumference point1
        phi1 = Uniform(0, 360);
        x1 = alpha + (rho * cos(phi1 * (PI / 180)));
        y1 = beta + (rho * sin(phi1 * (PI/180)));

        //  Randomly chosen x- and y-axis circumference point2
        phi2 = Uniform(0, 360);
        x2 = alpha + (rho * cos(phi2 * (PI / 180)));
        y2 = beta + (rho * sin(phi2 * (PI/180)));

        //  Distance between two points
        distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));

        //  Counts number of times dist is larger than rho
        if (distance > rho)
          count = count + 1;

        //  Troubleshoot
        if (DEBUG == 1)
          printf("Point 1 == phi: %.2f\tx: %.2f\ty: %.2f\nPoint 2 == phi: %.2f\tx: %.2f\ty: %.2f\nDistance: %.2f\nCount: %ld\n\n", phi1, x1, y1, phi2, x2, y2, distance, count);
    }

    //  Probability that distance > rho
    printf("\nNumber of iterations: %ld\n", i);
    printf("\talpha: %.2f\tbeta: %.2f\trho: %.2f\n", alpha, beta, rho);
    printf("\tP(X=dist > rho) = %.2f\n\n", ((float) count / (float) i));

    return (0);
}
