#include <stdio.h>
#include "util.h"

/*---Variables for the calculating the gcd of fractions---*/
int i,gcd;

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;
    *d3 = d1*n2;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {

    gcd=*n * *d; /* Multiplying the numerator and denominator for finding their greatest common divisor */

    if(gcd<0) /* If the number is less than zero we must convert it to positive  */
    {
        gcd=-gcd;

    }

    for(i=gcd;i>0;i--){ /* Simplification of numerator and denominator  */
        if(*d%i==0 & *n%i==0){
            *n=*n/i;
            *d=*d/i;

        }
    }

} /* end fraction_div */
