#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 5 //* bounds

/* Function declaration */
void formMatrix(int size, int matrix[][MAX]);
void printMatrix(int mat[][MAX], int size);
void isEvenLine(int mat[][MAX], int size);
void isMonoAscOrDesc(int mat[][MAX], int size);

bool isMonoAsc(int arr[], int size);
bool isMonoDesc(int arr[], int size);

int main()
{
    int N, i, j;
    scanf("%d", &N);

    int mat[N][N];

    /*Input elements in matrix using function*/
    formMatrix(N, mat);

    /*Print resultant array*/
    printMatrix(mat, N);

    isEvenLine(mat, N);

    isMonoAscOrDesc(mat, N);

    return 0;
}


/**
 * Function to accept a two dimensional array and print
 * its elements.
 *
 * @mat     Two dimensional integer array to p  rint.
 */
void printMatrix(int mat[][MAX], int size)
{
    int i, j;

    // Print elements of two dimensional array.
    printf("Elements in matrix: \n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

/**
 * Function to add create quadric matrice.
 * @size    length of matrix
 * @matrix    2 dimentional matrix blueprint.
 */
void formMatrix(int size, int matrix[][MAX]){
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % (100);
        }
    }
}

/**
 * Function to test if a matrix contains lines with all even values.
 * @size    length of matrix
 * @matrix    2 dimentional matrix blueprint.
 */
void isEvenLine(int mat[][MAX], int size) {
    int j, i;
    bool flag;

    for(i = 0; i < size; i++) {
        int j = 0;

        while(j < size){

            if(mat[i][j]%2 != 0){
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


/**
 * Function to test if a matrix contains lines with monotonic sequence, both ascending/descending.
 * @size    length of matrix
 * @matrix    2 dimentional matrix blueprint.
 */
void isMonoAscOrDesc(int mat[][MAX], int size) {
    int j, i;
    bool flag;
    for(i = 0; i < size; i++) {
        flag = isMonoAsc(mat[i], size) || isMonoDesc(mat[i], size);
        printf("%d line contains", i);
        printf("%s\n", flag ? " mono sequence" : " not mono sequence");
    }
}

/**
 * Function to test if a line contains values which form monotonic sequence ascending.
 * @size    length of matrix
 * @line    single dimensional array repsenting line
 */

bool isMonoAsc(int line[], int size) {
    int i = 0;
    bool flag;

    while(i < (size - 1) ) {
        if(line[i] > line[i+1]){
            flag = false;
            break;
        }

        flag = true;
        i++;
    }

    return flag;
}

/**
 * Function to test if a line contains values which form monotonic sequence descending.
 * @size    length of matrix
 * @line    single dimensional array repsenting line
 */
bool isMonoDesc(int line[], int size) {
    int i = 0;
    bool flag;

    while(i < (size - 1)){
        if(line[i] < line[i+1]){
            flag = false;
            break;
        }

        flag = true;
        i++;
    }

    return flag;
}
