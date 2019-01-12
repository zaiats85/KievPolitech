#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Option 5 zpi-zp82-005*/
const int k = 35;
float s;
float calculateSequenceForLoop(float s, int k);
float calculateSequenceWhileLoop(float s, int k);
float calculateSequenceDoWhileLoop(float s, int k);

/* Represent sequence ∑ = log10(√s * 1/i**2) for i= (1..k)*/
int main() {

    printf ("Please input s: ");
    scanf("%f", &s);

    if( s <= 0) {
        printf("Log10 is only defined for x > 0. Please change your input \n");
    } else {
        printf("sum in forLoop is %f. \n", calculateSequenceForLoop(s, k));
        printf("sum in whileLoop is %f. \n", calculateSequenceWhileLoop(s, k));
        printf("sum in doWhileLoop is %f. \n", calculateSequenceDoWhileLoop(s, k));
    }

/*return value int*/
    return 0;
}

float calculateSequenceForLoop(float s, int k){
    float result = 0;

    for(int i = 1; i < k; i++) {
        result += log10(sqrt(s/pow( i, 2)));
    }

    return result;

}

float calculateSequenceWhileLoop(float s, int k){
    float result = 0;
    int i = 1;

    while( i < k ){
        result += log10(sqrt(s/pow( i++, 2)));
    }

    return result;

}

float calculateSequenceDoWhileLoop(float s, int k){
    float result = 0;
    int i = 1;

    /* do loop execution */
    do {
        result += log10(sqrt(s/pow( i++, 2)));
    } while( i < k );

    return result;

}