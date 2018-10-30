#include <stdio.h>
#include <string.h>

const int TAB_SIZE = 8;

/*Option 5 zpi-zp82-005*/
float a = 2.54;
float b = 1.23;
float c = -2.14;
float d = -0.23;


int main() {
    char words[80];

    printf("Enter a string, and I ll count spaces for u : ");

/*get string from user, cant use gets as it is claimed to be unsafe*/
    fgets(words, 80, stdin);

/*assign amount of spaces to 0*/
    int spaces = 0;

/*calc spaces*/
    for (int i = 0; i < strlen(words); i++) {
        switch (words[i]) {
            /*whitespace*/
            case ' ':
                spaces++;
                break;

            /*tab*/
            case '\t':
                spaces += TAB_SIZE;
                break;

            default:
            /*escape if that is neither whitespace nor tab*/
                break;
        }
    }

/*output*/
    printf("\n Amount of spaces %d\n", spaces);

    char result[50] = "I am calculating\n";

    void calculateTrigonometricStatement(result);

/*return value int*/
    return 0;
}

char *calculateTrigonometricStatement(char str[]){

    printf("\n a is %f\n", a);
    printf("\n a is %f\n", b);
    printf("\n a is %f\n", c);
    printf("\n a is %f\n", d);

    return str;
}