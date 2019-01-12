#include <stdio.h>
#include <string.h>

const int TAB_SIZE = 8;

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

/*return value int*/
    return 0;
}
