#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Option 5 zpi-zp82-005*/
const int k = 35;
float s;
float calculateSequence(float s, int k);

/* Represent sequence ∑ = log10(√s * 1/i**2) for i= (1..k)*/
int main() {

    printf ("Please input s: ");
    scanf("%f", &s);

    if( s <= 0) {
        printf("Log10 is only defined for x > 0. Please change your input \n");
    } else {
        printf("sum is %f. \n", calculateSequence(s, k));
    }

/*return value int*/
    return 0;
}

float calculateSequence(float s, int k){
    float result = 0;

    for(int i = 1; i < k; i++) {
        result += log10(sqrt(s/pow( i, 2)));
    }

    return result;

}
