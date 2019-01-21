#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN         20  /* words maximum count */
#define MAX_CHARS       20  /* chars maximum length */
#define MAX_WORDLEN     20  /* word maximum length */

int main(int argc, char *argv[]) {

    /*Declaration*/
    int i, j, count, len[MAX_WORDLEN];

    /*Initialization*/
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

    /* read words from file to array */
    while (i < MAX_LEN && (fscanf(fp, "%s", words[i++]) != EOF));

    /* count words */
    count = i - 1;

    printf("WORDS: ");
    for (i = 0; i < count; ++i)
    {
        printf("%s, ", words[i]);
    }

    printf("\n\n");

    memset(len, 0, sizeof(int) * MAX_WORDLEN);

    /* count words length */
    for (i = 0; i < count; ++i)
    {
        len[strlen(words[i])]++;
    }

    /* result */
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
}