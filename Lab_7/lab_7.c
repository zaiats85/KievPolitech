#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void formMatrix(int **mat, int size);
void printMatrix(int **mat, int size);
void isEvenLine(int **mat, int size);

void isMonoAscOrDesc(int **mat, int size);
bool isMonoAsc(int *arr, int size);
bool isMonoDesc(int *arr, int size);

// Dynamically Allocate Memory for 2D Array
int main()
{
    int N = 0; //variable storing rank

    printf("\nEnter the number of Row = ");
    scanf("%d", &N); //Get input for rank

    // dynamically create array of pointers of size N
    int **ptr = (int **)malloc(N * sizeof(int *));
    if (ptr == NULL)
    {
        fprintf(stderr, "Out of memory");
        exit(0);
    }

    formMatrix((int **)ptr, N);
    printMatrix((int **)ptr, N);
    isEvenLine((int **)ptr, N);
    isMonoAscOrDesc((int **)ptr, N);

    // deallocate memory
    for (int i = 0; i < N; i++)
        free(ptr[i]);

    free(ptr);

    return 0;
}

void formMatrix(int **ptr, int N)
{
    int i, j;

    // dynamically allocate memory of size N for each row
    for (int i = 0; i < N; i++)
    {
        ptr[i] = (int *)malloc(N * sizeof(int));
        if (ptr[i] == NULL)
        {
            fprintf(stderr, "Out of memory");
            exit(0);
        }
    }

    // assign values to allocated memory
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            *(ptr[i] + j) = rand() % 100;
}

void printMatrix(int **ptr, int N)
{
    int i, j;

    // Print elements of two dimensional array.
    printf("Elements in 2D array: \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", *(ptr[i] + j));

        printf("\n");
    }
}

void isEvenLine(int **ptr, int N) {
    int j, i;
    bool flag;

    for(i = 0; i < N; i++) {
        int j = 0;
        while(j < N){
            if(*(ptr[i] + j)%2 != 0)
            {
                flag = false;
                break;
            }
            flag = true;
            j++;
        }

        printf("%d line contains ", i);
        printf("%s\n", flag ? " even values" : " odd values");
    };
}

void isMonoAscOrDesc(int **ptr, int N) {
    int j, i;
    bool flag;

    for(i = 0; i < N; i++) {
        /*Pointer Ariphmetics*/
        flag = isMonoAsc(ptr[i], N) || isMonoDesc(ptr[i], N);

        printf("%d line contains", i);
        printf("%s\n", flag ? " mono sequence" : " not mono sequence");
    }
}


bool isMonoAsc(int *line, int N) {
    int i = 0;
    bool flag;

    while(i < N-1) {

        if( *(line + i) > *(line + i + 1)){
            flag = false;
            break;
        }

        flag = true;
        i++;
    }

    return flag;
}


bool isMonoDesc(int *line, int N) {
    int i = 0;
    bool flag;

    while(i < N-1){

        if( *(line + i) < *(line + i + 1)){
            flag = false;
            break;
        }

        flag = true;
        i++;
    }

    return flag;
}
