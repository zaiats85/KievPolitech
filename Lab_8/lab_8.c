/**
 * C program to check alphabet, digit or special character using ASCII value
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isLetter(char ch);
char *inputString(FILE* fp, size_t size);

int main(void){
    char *words;
    int letters = 0;
    int nonLetters = 0;

    printf("Enter a string, and I ll count letters and non letters for u : ");
    words = inputString(stdin, 10);

    /*invariant*/
    int n = strlen(words);

    /*calc symbols*/
    for (int i = 0; i < n; i++)
        isLetter(words[i]) ? letters++ : nonLetters++;

    /*output*/
    printf("\n Amount of letters %d\n Amount of non letters %d\n", letters, nonLetters);

    printf("%s\n", words);

    free(words);
    return 0;
}

bool isLetter (char ch) {
    return ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90));
}

char *inputString(FILE* fp, size_t size) {
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;

    //size is start size
    str = realloc(NULL, sizeof(char)*size);
    if(!str) return str;

    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;

        /* Give me more space if exceeding */
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str) return str;
        }
    }

    /*end of input*/
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
}
