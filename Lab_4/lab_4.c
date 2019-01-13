#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define NUM_ITEMS 1000 /* Max numbers in file */

int array[NUM_ITEMS];
bool isEven(int n);
bool isBaseOdd(int n);

int main(int argc, char *argv[])
{
    FILE *fp;
    int i, even = 0, odd = 0, count = 0;

    /*object that identifies the stream*/
    fp = fopen(argv[1], "r");

    if (!fp)
    {
        printf("Can't open the file provided\n");
        return 0;
    }


    while (count < NUM_ITEMS && fscanf(fp, "%d", &count) != EOF)
    {
        if (isEven(count))
            even++;
        else if (isBaseOdd(count))
            odd++;
        count++;
    }

    fclose(fp);
    printf("odd: %d, even: %d\n", odd, even);
    return 0;
}

bool isEven(int n)
{
    return (n % 2 == 0);
}

bool isBaseOdd(int n)
{
    if(n > 0) {
        float f = sqrt(n);
        return (floor(f) == f && !isEven((int)f));
    } else {
        printf("There is a negative, odd integer: %d \n", n );
        return 0;
    }
}