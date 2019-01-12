/**
 * C program to check alphabet, digit or special character using ASCII value
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isLetter(char ch);

int main()
{
    char words[80];
    int letters = 0;
    int nonLetters = 0;

    printf("Enter a string, and I ll count letters and non letters for u : ");
    /*get string from user, cant use gets as it is claimed to be unsafe*/
    fgets(words, 80, stdin);

    /*invariant*/
    int n = strlen(words);

    /*calc symbols*/
    for (int i = 0; i < n-1; i++)
        isLetter(words[i]) ? letters++ : nonLetters++;

    /*output*/
    printf("\n Amount of letters %d\n Amount of non letters %d\n", letters, nonLetters);

    return 0;
}

bool isLetter (char ch) {
    return ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90));
}