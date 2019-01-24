#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // integer variables
    int N = 0;
    int sum = 0;
    int i;

    // integer pointer variables
    int *iptr, *tmp;

    // take user input
    printf("Enter value of N [1-10]: ");
    scanf("%d", &N);

    // allocate memory
    iptr = (int *) malloc (N * sizeof(int));

    // check if memory allocated
    if (iptr == NULL) {
        printf("Unable to allocate memory space. Program terminated.\n");
        return -1;
    }


    // take integers
    printf("Enter %d integer number(s)\n", N);
    for (i = 0, tmp = iptr; i < N; i++, tmp++) {
        printf("Enter #%d: ", (i+1));
        scanf("%d", tmp);

        // compute the sum
        sum += *tmp;
    }

    // display result
    printf("Sum: %d\n", sum);

    // free memory location
    free(iptr);

    return 0;
}

/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN         20  */
/* words maximum count *//*

#define MAX_CHARS       20  */
/* chars maximum length *//*

#define MAX_WORDLEN     20  */
/* word maximum length *//*


int main(int argc, char *argv[]) {

    */
/*Declaration*//*

    int i, j, count, len[MAX_WORDLEN];

    */
/*Initialization*//*

    i = 0;
    j = 0;
    count = 0;

    char words[MAX_LEN][MAX_WORDLEN];
    FILE *fp = NULL;

    fp = fopen(argv[1], "r");

    if (!fp) {
        printf("Can't open the file provided\n");
        return 0;
    }

    */
/* read words from file to array *//*

    while (i < MAX_LEN && (fscanf(fp, "%s", words[i++]) != EOF));

    */
/* count words *//*

    count = i - 1;

    printf("WORDS: ");
    for (i = 0; i < count; ++i)
    {
        printf("%s, ", words[i]);
    }

    printf("\n\n");

    memset(len, 0, sizeof(int) * MAX_WORDLEN);

    */
/* count words length *//*

    for (i = 0; i < count; ++i)
    {
        len[strlen(words[i])]++;
    }

    */
/* result *//*

    for (i = 0; i < MAX_WORDLEN; ++i)
    {

        if(len[i]){
            printf("%d: ", i);
            for (j = 0; j < len[i]; ++j)
                printf("+");
            printf("\n");
        }

    }

    printf("\n");

    return 0;
}*/
