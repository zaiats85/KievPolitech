#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Option 5 zpi-zp82-005*/
/*const float A = 2.54;
const float B = 1.23;
const float C = -2.14;
const float D = -0.23;*/
float A;
float B;
float C;
float D;

/* Represent calculation f(x) = 2*cos(a^b) + | arccos(-√c/d) | */
int main() {

    scanf("%f %f %f %f", &A, &B, &C, &D);

    /*arccos(x) = y; cos(y) = x; 0 < = y <= П, |x|<=1;*/
    float argument = -sqrt(C/D);

    if( fabs(argument) <= 1) {
        printf("f(x) = 2*cos(a^b) + | arccos(-√c/d) | result is %f \n", 2*cos(pow(A, B)) + abs(acos(argument)));

    } else {
        printf("%s\n", "The arccosine of x is defined as the inverse cosine function of x when -1 ≤ x ≤ 1.");
        printf("You can not calculate arccos of x = %f \nExceptional condition |argument| > 1. \n", argument);
    }

/*return value int*/
    return 0;
}
